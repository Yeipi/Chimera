/************************************************************************/
/**
 * @file chPath.h
 * @author AccelMR
 * @date 2022/06/23
 * @brief Path that is generic to platform so it can be used along the engine with
 *        no problem.
 */
 /************************************************************************/
#pragma once

/************************************************************************/
/*
 * Includes
 */                                                                     
/************************************************************************/
#include "chPrerequisitesUtilities.h"
#include <filesystem>  // for std::filesystem

namespace chEngineSDK {
namespace fs = std::filesystem;

class CH_UTILITY_EXPORT Path {
 public:
  /**
   * Default constructor.
   */
  FORCEINLINE
  Path() 
    : m_path() {}

  /**
   * Constructor from a simple string.
   * 
   * @param path
   *    As string.
   */
  Path(const String& path);

#if USING(CH_PLATFORM_WIN32)
  /**
   * Constructor from a wide string. Windows Only constructor.
   * 
   * @param path
   *    As Wide string.
   */
  Path(const WString& path);
#endif

  /**
   * Default destructor.
   */
  FORCEINLINE
  ~Path() = default;

  /**
   * Checks if path is relative.
   * 
   * @return True if path is relative, false for absolute path.
   */
  bool 
  isRelative() const;

  /**
   * Constructs a string from this path.
   * 
   * @return Path as a string.
   */
  String
  toString() const;

  /*
  * Check if path exists
  */
  bool
  exists() const;

  /**
   * Constructs a wide string from this path, platform-specific.
   * 
   * @return Path as a wide string (Windows) or regular string (other platforms).
   */
#if USING(CH_PLATFORM_WIN32)
  WString
#else
  String
#endif 
  getPlatformString() const;

  /**
   * Checks if this Path exists in the system.
   * 
   * @return True if exists, false otherwise.
   */
  bool
  exist() const;

  /**
   * Checks if path is a directory.
   * 
   * @return True if directory, false otherwise.
   */
  FORCEINLINE bool
  isDirectory() const;

  /**
   * Checks if path is a file.
   * 
   * @return True if file, false otherwise.
   */
  FORCEINLINE bool
  isFile() const;

  /**
   * Sets and sanitizes the internal path.
   * 
   * @param path
   *    The new string to be a path.
   */
  FORCEINLINE void
  setPath(const String& path);

  /**
   * Returns the file name of this path.
   * 
   * @param extension
   *    Include extension if true.
   * @return File name as a string.
   */
  String
  getFileName(bool extension = true) const;

  /**
   * Returns the extension of this path.
   * 
   * @return Extension as a string.
   */
  String
  getExtension() const;

  /**
   * Returns the directory of this path.
   * 
   * @return Directory as a string.
   */
  String
  getDirectory() const;

  /**
   * Joins this path with another path.
   * 
   * @param rhs
   *    The path to join with.
   * @return The joined path.
   */
  FORCEINLINE Path
  join(const Path& rhs) const;

  /**
   * Operator for less than, required for sorting, maps, etc.
   * 
   * @param other
   *    The path to compare to.
   * @return True if this path is less than the other path.
   */
  FORCEINLINE bool
  operator<(const Path& other) const;

private:
  fs::path m_path;  // Using C++17 std::filesystem::path
};
}  // namespace chEngineSDK