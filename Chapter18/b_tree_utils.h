#pragma once

template <typename KeyType>

void insert_key(KeyType *arrKeys, int keyCount, KeyType key)
{
    int index = 0;
    while (index < keyCount && key > arrKeys[index])
    {
        ++index;
    }
    int begin = keyCount + 1;
    while (begin > index)
    {
        arrKeys[begin] = arrKeys[begin - 1];
        begin--;
    }
    arrKeys[index] = key;
}