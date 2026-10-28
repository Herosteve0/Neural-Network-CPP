#include "DataStructs.h"

namespace NeuralNetwork::Data {
    DataBatch::DataBatch(const std::span<MnistDataSample> data) : BatchBase(data) {}
    DataBatch::DataBatch(MnistDataSample data) : BatchBase(std::span(&data, 1)) {}

    DataBatch DataBatch::CreateBatch(const std::span<MnistDataSample> data) const {
        return DataBatch(data);
    }

    GuessBatch::GuessBatch(const std::span<MnistDataGuess> data) : BatchBase(data) {}
    GuessBatch::GuessBatch(MnistDataGuess data) : BatchBase(std::span(&data, 1)) {}

    GuessBatch GuessBatch::CreateBatch(const std::span<MnistDataGuess> data) const {
        return GuessBatch(data);
    }
}
