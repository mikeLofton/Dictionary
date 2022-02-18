**Michael Lofton**

s218033 

Code Design and Data Structures

Dictionary

# I. Requirements
    
 1. **Description of Problem**

    **Name:** Dictionary

    **Problem Statement:** 

    Implement a Dictionary

    **Problem Specifications:**
    
    * Completion of functons given in the UML. 

 2. **Input Information:**
    * Functions can be tested in the main class.
 3. **Output Information:**
    * The results of the functions can be printed in the console window.

# II. Design
 1. *System Architecture*
    
    Dictionary.h contains the Dictionary templeted class. The Dictionary class has two typenames, TKey and TValue. Dictionary contains logic for adding and removing items to/from the items array. The dictionary can check for a specific key or value and can return values at the given key. Within the Dictionary class is the Item struct. Items can have a key and a value. main.cpp includes Dictionary.h and iostream. Main contains a test dictionary and functions can be called there for testing purposes. 
 2. *Object Information*
    * **File Name:** main.cpp
        * Name: main()
            * Description: Runs the test code.
            * Visibility: public
            * Type: int
    * **File Name:** Dictionary.h
        * **Class Name:** Dictionary (template: typename TKey, TValue) 
        * Name: Dictionary-Tkey, TValue-()
            * Description: Dictionary Base Constructor. Sets the items array to null pointer and the item count to zero.
            * Visibility: public
        * Name: Dictionary-Tkey, TValue-(const Dictionary-Tkey, TValue-& other)
            * Description: Constructor that copies the values of the other dictionary into this one.
            * Visibility: public
        * Name: ~Dictionary-Tkey, TValue-()
            * Description: Dictionary Destructor. Deletes all items in the dictionary.
            * Visibility: public
        * Name: clear()
            * Description: Deletes all items in the dictionary.
            * Visibility: public
            * Type: void
        * Name: containsKey(const TKey object) const
            * Description: Checks to see if an item in the dictionary has the given key.
            * Visibility: public
            * Type: bool
        * Name: containsValue(const TValue object) const
            * Description: Checks to see if an item in the dictionary has the given value.
            * Visibility: public
            * Type: bool
        * Name: tryGetValue(const TKey key, TValue& value) const
            * Description: Checks for an item that has the given key then returns its value.
            * Visibility: public
            * Type: bool
        * Name: addItem(const TKey& key, const TValue& value)
            * Description: Adds a new item to the dictionary that has the given key and contans the given value.
            * Visibility: public
            * Type: void
        * Name: remove(const TKey key)
            * Description: Removes the item with the given key.
            * Visibility: public
            * Type: bool
        * Name: remove(const Tkey key, TValue& value)
            * Description: Removes the item with the given key and returns the value of the removed item.
            * Visibility: public
            * Type: bool
        * Name: getCount() const
            * Description: Returns the number of items in the dictionary.
            * Visibility: public
            * Type: int
        * Name: =(const Dictionary-Tkey, TValue- other)
            * Description: Copies the values of the other dictionary onto this one.
            * Visibility: public
            * Type: const Dictionary-Tkey, TValue-& operator
        * Name: [](const TKey key)
            * Description: Returns a value with the given key.
            * Visibility: public
            * Type: TValue operator
        * Name: m_items(Item*)
            * Description: Pointer to the array of items.
            * Visibility: private
        * Name: m_count(int)
            * Description: The number of items in the dictionary.
            * Visibility: private
        * **Struct Name:** Item
        * Name: itemKey(TKey)
            * Description: The item's key.
            * Visibility: private
        * Name: itemValue(TValue)
            * Description: The item's value.
            * Visibility: private