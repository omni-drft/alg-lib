#ifndef ALGLIB_INCLUDE_CONSTANTS_H_
#define ALGLIB_INCLUDE_CONSTANTS_H_

#include <string>

/// <summary>
/// Default namespace for the AlgLib library.
/// </summary>
namespace alglib {

/// <summary>
/// Namespace for errors in the AlgLib library.
/// </summary>
namespace errors {

// Error messages.
constexpr const char* kItemNotFound{"Item not found."};
constexpr const char* kIndexOutOfRange{"Index out of range."};
constexpr const char* kEmptyDeletion{"Cannot delete from empty object."};

}  // namespace errors

}  // namespace alglib

#endif  // ALGLIB_INCLUDE_CONSTANTS_H_
