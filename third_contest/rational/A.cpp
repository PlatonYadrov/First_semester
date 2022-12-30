#include "rational.h"
#include <iostream>
#include <cmath>

Rational::Rational() : p_(0), q_(1) {
}
Rational::Rational(int n) : p_(n), q_(1) {
}
Rational::Rational(int n, int m) : p_(n), q_(m) {
  NormalRation();
}

void Rational::NormalRation() {
  if (q_ == 0) {
    throw RationalDivisionByZero();
  }
  if (q_ < 0) {
    p_ = -p_;
    q_ = -q_;
  }
  int abs_p = std::abs(p_);
  int abs_q = std::abs(q_);
  while (abs_q != 0) {
    int temp = abs_p;
    abs_p = abs_q;
    abs_q = temp % abs_q;
  }
  int k = abs_p;
  p_ = p_ / k;
  q_ = q_ / k;
}

void Rational::Updare(Rational& rat) {
  std::swap(p_, rat.p_);
  std::swap(q_, rat.q_);
}

int Rational::GetNumerator() const {
  return p_;
}

int Rational::GetDenominator() const {
  return q_;
}

void Rational::SetNumerator(int now) {
  p_ = now;
  NormalRation();
}

void Rational::SetDenominator(int now) {
  q_ = now;
  NormalRation();
}

Rational& Rational::operator=(Rational rat) {
  rat.NormalRation();
  Updare(rat);
  return *this;
}

Rational& operator++(Rational& rat) {
  int numerator = rat.GetNumerator();
  int denominator = rat.GetDenominator();
  rat.SetNumerator(numerator + denominator);
  rat.NormalRation();
  return rat;
}

Rational& operator--(Rational& rat) {
  int numerator = rat.GetNumerator();
  int denominator = rat.GetDenominator();
  rat.SetNumerator(numerator - denominator);
  rat.NormalRation();
  return rat;
}

Rational operator++(Rational& rat, int) {
  Rational temp = rat;
  int numerator = rat.GetNumerator();
  int denominator = rat.GetDenominator();
  rat.SetNumerator(numerator + denominator);
  return temp;
}

Rational operator--(Rational& rat, int) {
  Rational temp = rat;
  int numerator = rat.GetNumerator();
  int denominator = rat.GetDenominator();
  rat.SetNumerator(numerator - denominator);
  return temp;
}

Rational& operator+=(Rational& rat_one, const Rational& rat_two) {
  Rational& temp = rat_one;
  temp = temp + rat_two;
  return temp;
}

Rational& operator-=(Rational& rat_one, const Rational& rat_two) {
  Rational& temp = rat_one;
  temp = temp - rat_two;
  return temp;
}

Rational& operator*=(Rational& rat_one, const Rational& rat_two) {
  Rational& temp = rat_one;
  temp = temp * rat_two;
  return temp;
}

Rational& operator/=(Rational& rat_one, const Rational& rat_two) {
  Rational& temp = rat_one;
  temp = temp / rat_two;
  return temp;
}

Rational operator+(const Rational& rat_one, const Rational& rat_two) {
  int p = rat_one.GetNumerator() * rat_two.GetDenominator() + rat_two.GetNumerator() * rat_one.GetDenominator();
  int q = rat_one.GetDenominator() * rat_two.GetDenominator();
  return Rational(p, q);
}

Rational operator-(const Rational& rat_one, const Rational& rat_two) {
  int p = rat_one.GetNumerator() * rat_two.GetDenominator() - rat_two.GetNumerator() * rat_one.GetDenominator();
  int q = rat_one.GetDenominator() * rat_two.GetDenominator();
  return Rational(p, q);
}

Rational operator*(const Rational& rat_one, const Rational& rat_two) {
  int p = rat_one.GetNumerator() * rat_two.GetNumerator();
  int q = rat_one.GetDenominator() * rat_two.GetDenominator();
  return Rational(p, q);
}

Rational operator/(const Rational& rat_one, const Rational& rat_two) {
  int p = rat_one.GetNumerator() * rat_two.GetDenominator();
  int q = rat_one.GetDenominator() * rat_two.GetNumerator();
  return Rational(p, q);
}

Rational operator+(const Rational& rat) {
  int p = rat.GetNumerator();
  int q = rat.GetDenominator();
  return Rational(p, q);
}

Rational operator-(const Rational& rat) {
  int p = -rat.GetNumerator();
  int q = rat.GetDenominator();
  return Rational(p, q);
}

bool operator==(const Rational rat_one, const Rational rat_two) {
  int numerator_one = rat_one.GetNumerator();
  int numerator_two = rat_two.GetNumerator();
  int denominator_one = rat_one.GetDenominator();
  int denominator_two = rat_two.GetDenominator();
  if (numerator_one * denominator_two == denominator_one * numerator_two) {
    return (1 == 1);
  }
  return (1 == 0);
}

bool operator!=(const Rational rat_one, const Rational rat_two) {
  return !(rat_one == rat_two);
}

bool operator<(const Rational rat_one, const Rational rat_two) {
  int numerator_one = rat_one.GetNumerator();
  int numerator_two = rat_two.GetNumerator();
  int denominator_one = rat_one.GetDenominator();
  int denominator_two = rat_two.GetDenominator();
  if (numerator_one * denominator_two < denominator_one * numerator_two) {
    return (1 == 1);
  }
  return (1 == 0);
}

bool operator>(const Rational rat_one, const Rational rat_two) {
  int numerator_one = rat_one.GetNumerator();
  int numerator_two = rat_two.GetNumerator();
  int denominator_one = rat_one.GetDenominator();
  int denominator_two = rat_two.GetDenominator();
  if (numerator_one * denominator_two > denominator_one * numerator_two) {
    return (1 == 1);
  }
  return (1 == 0);
}

bool operator<=(const Rational rat_one, const Rational rat_two) {
  return !(rat_one > rat_two);
}

bool operator>=(const Rational rat_one, const Rational rat_two) {
  return !(rat_one < rat_two);
}

std::istream& operator>>(std::istream& element, Rational& rat) {
  int32_t n;
  int32_t m;
  char t;
  element >> n;
  if (element.peek() != '/') {
    rat = Rational(n);
    return element;
  }
  element >> t;
  element >> m;
  rat = Rational(n, m);
  return element;
}

std::ostream& operator<<(std::ostream& element, const Rational& rat) {
  if (rat.GetDenominator() == 1) {
    element << rat.GetNumerator();
    return element;
  }
  element << rat.GetNumerator() << '/' << rat.GetDenominator();
  return element;
}
