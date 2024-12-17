# Case 1

The case here is to be able to fully cover the code inside of this class using tests.

> **Assumption**  
> The `library::Storage` can't be changed since it's an external
dependency

This implementation can't be fully covered because `m_storage.put(val)`
will never return false thus on of the branches in the `if` statement will not be covered.
