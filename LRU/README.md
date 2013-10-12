HOW TO WRITE A LRU CACHE
===

Basics
---

We will need a _counter_ to represent the order of access of elements. If _x_ is accessed at the beginning then it's `counter[x]=0`. If _y_ is accessed next then `counter[y]=1`. If after that _x_ is accessed then we update `counter[x] = 2`.  

Two hashmaps are requred. One will map each `key` to `(value, counter_val)` pair. And other will be a helper hashmap which maps `counter_val` variable to the `key`.

###Code With Explanation

```
    class Pair {
        string value;
        int counter_val;
    }

    HashMap <String, Pair> keys = new HashMap <String, Pair> ();
    HashMap <Integer, String> counter = new HashMap <Integer, String> ();
    int beginCounter = 0, currentCounter = 0;
    final int CACHE_SIZE = 1000;

    // This function gets the value associated with key, and updates its counter also.
    string get(string key) {
        Pair element = keys.get(key);

        // If key doesn't exist, return 'null'.
        if(element == null)
            return null;
        
        //If keys exits.
        //Updates its value in 'counter' to 'currentCounter'.
        counter.remove(element.counter_val);
        counter.put(currentCounter, key);

        // Updates its counter in 'keys'.
        element.counter_val = currentCounter;
        keys.put(key, element);

        // Increments counter for next use.
        currentCounter++;

        return element.value;
    }

    void put(string key, string val) {
        Pair element = keys.get(key);

        //If keys exits.
        if(element != null) {
            //Update it value in 'counter' to 'currentCounter'.
            counter.remove(element.counter_val);
            counter.put(currentCounter, key);

            element.counter_val = currentCounter;
            element.value = val;
            keys.put(key, element);

            currentCounter++;
        } 
        //If key doesn't exists, add its entry in 'keys' and 'counter'.
        else { 
            element = new Pair(val, currentCounter);
            counter.put(currentCounter, key);
            keys.put(key, element);
            currentCounter++;

            // Checks whether cache size overshoots its size limit.
            resize();
        }
    }

    // It's check whether size of cache exceeds its limit and purge some element from it.
    void resize() {

        // We will search for element at beginCounter, and removes it untill caches size is witin limit.
        while(keys.size() > CACHE_SIZE){

            // If 'beginCounter' is not present, increment it and search for its new value;
            if(counter.containsKey(beginCounter) == false) {
                beginCounter++;
            } 

            // If 'beginCounter' is present remove it's entry.
            else {
                string key = counter.get(beginCounter);
                counter.remove(beginCounter);
                keys.remove(key);
                
                beginCounter++;
            }
        }
    }
```
