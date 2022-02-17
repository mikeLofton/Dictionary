#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other) { *this = other; }
	~Dictionary<TKey, TValue>() { clear(); }

	/// <summary>
	/// Deletes all items in dictionary
	/// </summary>
	void clear();

	/// <summary>
	/// Checks to see if an item that has the given key is in the dictionary
	/// </summary>
	/// <param name="object"></param>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// Checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object"></param>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// Tries to find the item that matches the given key
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	bool tryGetValue(const TKey key, TValue& value) const;

	/// <summary>
	/// Creates a new item with the given key and value and adds it to the dictionary
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	void addItem(const TKey& key, const TValue& value);

	/// <summary>
	/// Removes the item that has the given key
	/// </summary>
	/// <param name="key"></param>
	bool remove(const TKey key);

	/// <summary>
	/// Removes the item that has the given key 
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	/// <returns>Gives back the value of the item that was removed</returns>
	bool remove(const TKey key, TValue& value);

	/// <summary>
	/// Gets the number of items in the dictionary
	/// </summary>
	int getCount() const { return m_count; }

	const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);

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
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey == key)
		{
			value = m_items[i].itemValue;
			return true;
		}
	}
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	Item* tempArray = new Item[getCount() + 1];

	for (int i = 0; i < getCount(); i++)
	{
		tempArray[i].itemKey = m_items[i].itemKey;
		tempArray[i].itemValue = m_items[i].itemValue;
	}

	tempArray[m_count].itemKey = key;
	tempArray[m_count].itemValue = value;

	delete[] m_items;
	m_items = tempArray;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	if (!containsKey(key))
		return false;

	bool itemRemoved = false;
	Item* tempArray = new Item[getCount() - 1];
	int j = 0;

	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempArray[j].itemKey = m_items[i].itemKey;
			tempArray[j].itemValue = m_items[i].itemValue;
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	if (itemRemoved)
	{
		delete[] m_items;
		m_items = tempArray;
		m_count--;
	}

	return itemRemoved;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	if (!containsKey(key))
		return false;

	bool itemRemoved = false;
	Item* tempArray = new Item[getCount() - 1];
	int j = 0;

	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempArray[j].itemKey = m_items[i].itemKey;
			tempArray[j].itemValue = m_items[i].itemValue;
			j++;
		}
		else
		{
			itemRemoved = true;
			value = m_items[i].itemValue;
		}
	}

	if (itemRemoved)
	{
		delete[] m_items;
		m_items = tempArray;
		m_count--;
	}

	return itemRemoved;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	clear(); //Delete all items in the dictionary

	for (int i = 0; i < other.getCount(); i++)
	{
		m_items[i] = other.m_items[i];
	}

	m_count = other.getCount(); 

	return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	TValue value;

	tryGetValue(key, value);

	return value;
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
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey == object)
			return true;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemValue == object)
			return true;
	}
}
