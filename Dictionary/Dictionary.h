#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:

	/// <summary>
	/// Base Constructor
	/// </summary>
	Dictionary<TKey, TValue>();

	/// <summary>
	/// Copies the values of another dictionary to this one
	/// </summary>
	/// <param name="other"></param>
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other) { *this = other; }

	///Destructor clears the dictionary
	~Dictionary<TKey, TValue>() { clear(); }

	/// <summary>
	/// Deletes all items in dictionary
	/// </summary>
	void clear();

	/// <summary>
	/// Checks to see if an item that has the given key is in the dictionary
	/// </summary>
	/// <param name="object">The given key</param>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// Checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object">The given value</param>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// Tries to find the item that matches the given key and spit back the value
	/// </summary>
	/// <param name="key">The given key</param>
	/// <param name="value">The returned value</param>
	bool tryGetValue(const TKey key, TValue& value) const;

	/// <summary>
	/// Creates a new item with the given key and value and adds it to the dictionary
	/// </summary>
	/// <param name="key">The item key</param>
	/// <param name="value">The item value</param>
	void addItem(const TKey& key, const TValue& value);

	/// <summary>
	/// Removes the item that has the given key
	/// </summary>
	/// <param name="key">The given key</param>
	bool remove(const TKey key);

	/// <summary>
	/// Removes the item that has the given key, gives back the value of the item that was removed
	/// </summary>
	/// <param name="key">The given key</param>
	/// <param name="value">The returned value</param>
	bool remove(const TKey key, TValue& value);

	/// <summary>
	/// Gets the number of items in the dictionary
	/// </summary>
	int getCount() const { return m_count; }

	/// <summary>
	/// Copies the values of one dictionary into another
	/// </summary>
	/// <param name="other">The other dictionary</param>
	const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);

	/// <param name="key">The given key</param>
	/// <returns>Returns a value with the given key</returns>
	TValue operator [](const TKey key);

private:

	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	for (int i = 0; i < getCount(); i++) //While i is less than the item count
	{
		if (m_items[i].itemKey == key) //If the item key equals the given key
		{
			value = m_items[i].itemValue; //Set the value to the item's value
			return true; //Return true
		}
	}

	return false; //Return false by default
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	Item* tempArray = new Item[getCount() + 1]; //Create a temp array with a length of the item count + 1

	for (int i = 0; i < getCount(); i++) //While i is less than the item count
	{
		tempArray[i].itemKey = m_items[i].itemKey; //Set the temp array item keys to the items array item keys
		tempArray[i].itemValue = m_items[i].itemValue; //Set the temp array item values to the items array item values
	}

	tempArray[m_count].itemKey = key; //Add the given key to the temp array
	tempArray[m_count].itemValue = value; //Add the given value to the temp array

	delete[] m_items; //Delete the items in the items array
	m_items = tempArray; //Copy the temp array data into the item array
	m_count++; //Increment the item count
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	if (!containsKey(key)) //If the dictionary doesn't contain the key return false
		return false;

	bool itemRemoved = false;
	Item* tempArray = new Item[getCount() - 1]; //Create a temp array with a length of item count - 1
	int j = 0; //Create a j value set to zero

	for (int i = 0; i < getCount(); i++) //While i is less than the item count
	{
		if (m_items[i].itemKey != key) //If the item's key does not equal key
		{
			tempArray[j].itemKey = m_items[i].itemKey; //Set the temp array item keys to the items array item keys
			tempArray[j].itemValue = m_items[i].itemValue; //Set the temp array item values to the items array item values
			j++; //Increment j
		}
		else
		{
			itemRemoved = true; 
		}
	}

	if (itemRemoved) //If the item was removed
	{
		delete[] m_items; //Delete the items in the items array
		m_items = tempArray; //Copy the temp array data into the item array
		m_count--; //Decrement the item count
	}

	return itemRemoved; //Return item removed
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	if (!containsKey(key)) //If the dictionary doesn't contain the key return false
		return false;

	bool itemRemoved = false;
	Item* tempArray = new Item[getCount() - 1]; //Create a temp array with a length of item count - 1
	int j = 0; //Create a j value set to zero

	for (int i = 0; i < getCount(); i++) //While i is less than the item count
	{
		if (m_items[i].itemKey != key) //If the item's key does not equal key
		{
			tempArray[j].itemKey = m_items[i].itemKey; //Set the temp array item keys to the items array item keys
			tempArray[j].itemValue = m_items[i].itemValue; //Set the temp array item values to the items array item values
			j++; //Increment j
		}
		else
		{
			itemRemoved = true;
			value = m_items[i].itemValue; //Set value to the removed item's value
		}
	}

	if (itemRemoved) //If the item was removed
	{
		delete[] m_items; //Delete the items in the items array
		m_items = tempArray; //Copy the temp array data into the item array
		m_count--; //Decrement the item count
	}

	return itemRemoved; //Return item removed
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	clear(); //Delete all items in the dictionary

	for (int i = 0; i < other.getCount(); i++) //While i is less than the other dictionary's item count
	{
		m_items[i] = other.m_items[i]; //Copy the other dictionary's data into this one
	}

	m_count = other.getCount(); //Copy the item count

	return *this; //Return this
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	TValue value; //Create a value

	tryGetValue(key, value); //Call try get value

	return value; //Return value
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	delete[] m_items;
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	for (int i = 0; i < getCount(); i++) //While i is less than the item count
	{
		if (m_items[i].itemKey == object) //If the items key equals the key return true
			return true;
	}

	return false; //Return false by default
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemValue == object) //If the items value equals value return true
			return true;
	}

	return false; //Return false by default
}
