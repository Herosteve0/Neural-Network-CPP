#pragma once

namespace NeuralNetwork::Data {
    template<typename TSelf, typename TItem>
    BatchBase<TSelf, TItem>::BatchBase(std::span<TItem> data) {
        _data = std::move(data);
    }

    template<typename TSelf, typename TItem>
    int BatchBase<TSelf, TItem>::GetSize() const {
        return _data.size();
    }

    template<typename TSelf, typename TItem>
    TSelf BatchBase<TSelf, TItem>::GetSmallBatch(int index, int length) const {
        if (index + length > _data.size()) {
            length = _data.size() - index;
        }
        std::span<TItem> data = _data.subspan(index, length);
        return CreateBatch(data);
    }

    template<typename TSelf, typename TItem>
    void BatchBase<TSelf, TItem>::Shuffle(Random random) {
        for (int i = _data.size() - 1; i > 0; i--) {
            int r = random.NextInt(i + 1);
            swap(_data[i], _data[r]);
        }
    }
}