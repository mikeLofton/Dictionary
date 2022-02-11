#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
	~Dictionary<TKey, TValue>();

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
	bool tryGetValue(const TKey key, const TValue& value) const;

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
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	
}
