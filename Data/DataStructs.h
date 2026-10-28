#ifndef NEURAL_NETWORK_C_DATASTRUCTS_H
#define NEURAL_NETWORK_C_DATASTRUCTS_H

#include <span>
#include <vector>
#include "Random.h"

namespace NeuralNetwork::Data {
    template <typename TSelf, typename TItem>
    class BatchBase {
        std::span<TItem> _data;
    protected:
        virtual TSelf CreateBatch(std::span<TItem> data) const = 0;
    public:
        virtual ~BatchBase() = default;

        explicit BatchBase(std::span<TItem> data);

        /**
         * Returns the size of the batch.
         */
        int GetSize() const;

        TItem operator[](int index) {
            return _data[index];
        }

        TSelf GetSmallBatch(int index, int length) const;

        void Shuffle(Random random);
    };

    struct MnistDataSample {
        std::vector<float> Values;
        int Label;
    };

    class DataBatch final : public BatchBase<DataBatch, MnistDataSample> {
    protected:
        DataBatch CreateBatch(std::span<MnistDataSample> data) const override;
    public:
        explicit DataBatch(std::span<MnistDataSample> data);

        explicit DataBatch(MnistDataSample data);
    };

    struct MnistDataGuess {
        MnistDataSample Data;
        int Prediction{};
    };

    class GuessBatch final : public BatchBase<GuessBatch, MnistDataGuess> {
    protected:
        GuessBatch CreateBatch(std::span<MnistDataGuess> data) const override;
    public:
        explicit GuessBatch(std::span<MnistDataGuess> data);
        explicit GuessBatch(MnistDataGuess data);
    };
}

#include "DataStructs.hpp"

#endif
