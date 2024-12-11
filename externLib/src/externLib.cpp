#include "externLib.hpp"

/**
 * Library implementation
 *
 * Note:
 * This implementation is intentionally not perfect in order to show a more
 * real-life example
 */
namespace externLib
{
bool Storage::put(int val)
{
  m_val = val;
  m_hasValue = true;
  return true;
}

std::optional<int> Storage::get()
{
  if (!m_hasValue)
    return std::nullopt;

  m_hasValue = false;
  return m_val;
}
}  // namespace externLib
