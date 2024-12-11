#ifndef EX_LIB_HPP
#define EX_LIB_HPP

#include <optional>

namespace externLib
{

class Storage
{
public:
  /**
   * @brief Store @c val in the internal storage
   *
   * Note:
   * This implementation is intentionaly faulty and will @b never fail (it
   * will always return @c true).
   *
   * @return Operation status
   * @retval true Variable stored successfuly
   * @retval false Operation failed and the variable was not stored in the
   * storage
   */
  bool put(int val);

  std::optional<int> get();

private:
  bool m_hasValue = false;
  int m_val = 0;
};
}  // namespace externLib

#endif  // EX_LIB_HPP