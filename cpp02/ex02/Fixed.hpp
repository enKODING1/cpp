#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>

class Fixed
{
private:
  int _fixed_point;
  static const int _fractional_bits;

public:
  Fixed(const int n);
  Fixed(const float floating_point_n);
  Fixed();
  Fixed(const Fixed &other);
  ~Fixed();

  Fixed &operator=(const Fixed &other);
  /*comparison operator*/
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  /*arthmetic operator*/
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  /*increment/decrement*/
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  static Fixed &min(Fixed &n1, Fixed &n2);
  static const Fixed &min(const Fixed &n1, const Fixed &n2);
  static Fixed &max(Fixed &n1, Fixed &n2);
  static const Fixed &max(const Fixed &n1, const Fixed &n2);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_num);

#endif