#include <iostream>

int hash_func(int key_value, int size)
{
    return key_value % size;
}

void insert(int arr[], int size)
{
    int key_value;
    std::cout << "Enter the key value: ";
    std::cin >> key_value;
    int index = hash_func(key_value, size);

    while (arr[index] != 0)
    {
        // Linear probing to find the next available slot
        index = (index + 1) % size;
    }

    arr[index] = key_value;
}

bool search(int arr[], int size, int key)
{
    int index = hash_func(key, size);
    int initialIndex = index;

    while (arr[index] != 0)
    {
        if (arr[index] == key)
        {
            std::cout << "Key " << key << " found at index " << index << std::endl;
            return true;
        }
        index = (index + 1) % size; // Move to the next slot linearly

        // If we've checked the entire table, break the loop
        if (index == initialIndex)
        {
            break;
        }
    }

    std::cout << "Key " << key << " not found in the hash table." << std::endl;
    return false;
}

bool deleteKey(int arr[], int size, int key)
{
    int index = hash_func(key, size);
    int initialIndex = index;

    while (arr[index] != 0)
    {
        if (arr[index] == key)
        {
            arr[index] = 0; // Mark the slot as empty
            std::cout << "Key " << key << " deleted from index " << index << std::endl;
            return true;
        }
        index = (index + 1) % size; // Move to the next slot linearly

        // If we've checked the entire table, break the loop
        if (index == initialIndex)
        {
            break;
        }
    }

    std::cout << "Key " << key << " not found in the hash table. Deletion failed." << std::endl;
    return false;
}

int main()
{
    int size = 10;
    int arr[size] = {0}; // Initialize the array to 0

    for (int i = 0; i < size; i++)
    {
        insert(arr, size);
    }

    std::cout << "Hash Table: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " , ";
    }

    int key_to_search;
    std::cout << "\nEnter the key to search: ";
    std::cin >> key_to_search;
    search(arr, size, key_to_search);

    int key_to_delete;
    std::cout << "Enter the key to delete: ";
    std::cin >> key_to_delete;
    deleteKey(arr, size, key_to_delete);

    std::cout << "Updated Hash Table: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " , ";
    }

    return 0;
}
