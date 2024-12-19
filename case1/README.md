# Case 1 - External dependency

In this case we're focusing on the situation where our code uses an external dependency that doesn't have any interface class.

The object of that class is used by the internal algorithm of our implementation and is private member of our class `Foo`.

> **Assumption**  
> The `library::Storage` can't be changed since it's an external
dependency

This implementation can't be fully covered because `m_storage.put(val)`
will never return false thus on of the branches in the `if` statement will not be covered.
