/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:36:48 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/30 16:36:48 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// ========================================
// TESTS DES OPERATEURS DE COMPARAISON
// ========================================

TEST_CASE("Operateur ==") {
    Fixed a(5.5f);
    Fixed b(3.2f);
    Fixed c(5.5f);
    Fixed d(-2.1f);
    Fixed zero(0);

    SUBCASE("Egalite entre valeurs identiques") {
        CHECK(a == c);
        CHECK(zero == Fixed(0));
    }

    SUBCASE("Inegalite entre valeurs differentes") {
        CHECK(!(a == b));
        CHECK(!(d == a));
        CHECK(!(a == zero));
    }
}

TEST_CASE("Operateur !=") {
    Fixed a(5.5f);
    Fixed b(3.2f);
    Fixed c(5.5f);
    Fixed d(-2.1f);

    SUBCASE("Inegalite detectee correctement") {
        CHECK(a != b);
        CHECK(d != a);
        CHECK(b != c);
    }

    SUBCASE("Egalite detectee correctement") {
        CHECK(!(a != c));
        CHECK(!(a != a));
    }
}

TEST_CASE("Operateur >") {
    Fixed a(10.2f);
    Fixed b(5.9f);
    Fixed c(0);
    Fixed d(-0.6f);

    SUBCASE("Comparaison valeurs positives") {
        CHECK(a > b);
        CHECK(!(b > a));
        CHECK(b > c);
    }

    SUBCASE("Comparaison avec zero") {
        CHECK(a > c);
        CHECK(c > d);
        CHECK(!(c > c));
    }

    SUBCASE("Comparaison valeurs negatives") {
        CHECK(c > d);
        CHECK(!(d > c));
    }
}

TEST_CASE("Operateur <") {
    Fixed a(10.2f);
    Fixed b(5.9f);
    Fixed c(0);
    Fixed d(-0.6f);

    SUBCASE("Comparaison valeurs positives") {
        CHECK(b < a);
        CHECK(!(a < b));
        CHECK(c < b);
    }

    SUBCASE("Comparaison avec zero") {
        CHECK(d < c);
        CHECK(!(c < d));
        CHECK(!(c < c));
    }

    SUBCASE("Comparaison valeurs negatives") {
        CHECK(d < b);
        CHECK(d < a);
    }
}

TEST_CASE("Operateur >=") {
    Fixed a(10.2f);
    Fixed b(5.9f);
    Fixed c(0);
    Fixed d(-0.6f);

    SUBCASE("Strictement superieur") {
        CHECK(a >= b);
        CHECK(b >= c);
        CHECK(c >= d);
        CHECK(!(d >= c));
    }

    SUBCASE("Egalite") {
        CHECK(a >= a);
        CHECK(c >= c);
        CHECK(b >= Fixed(5.9f));
    }
}

TEST_CASE("Operateur <=") {
    Fixed a(10.2f);
    Fixed b(5.9f);
    Fixed c(0);
    Fixed d(-0.6f);

    SUBCASE("Strictement inferieur") {
        CHECK(b <= a);
        CHECK(c <= b);
        CHECK(d <= c);
        CHECK(!(c <= d));
    }

    SUBCASE("Egalite") {
        CHECK(a <= a);
        CHECK(c <= c);
        CHECK(b <= Fixed(5.9f));
    }
}

// ========================================
// TESTS DES OPERATEURS ARITHMETIQUES
// ========================================

TEST_CASE("Operateur +") {
    Fixed a(10.5f);
    Fixed b(3.0f);
    Fixed c(-5.25f);
    Fixed zero(0);

    SUBCASE("Addition valeurs positives") {
        Fixed result = a + b;
        CHECK(result.toFloat() == doctest::Approx(13.5f).epsilon(0.01));
    }

    SUBCASE("Addition avec negatif") {
        Fixed result = a + c;
        CHECK(result.toFloat() == doctest::Approx(5.25f).epsilon(0.01));
    }

    SUBCASE("Addition avec zero") {
        Fixed result = a + zero;
        CHECK(result == a);
    }

    SUBCASE("Addition de negatifs") {
        Fixed result = c + c;
        CHECK(result.toFloat() == doctest::Approx(-10.5f).epsilon(0.01));
    }
}

TEST_CASE("Operateur -") {
    Fixed a(10.5f);
    Fixed b(3.0f);
    Fixed c(-5.25f);
    Fixed zero(0);

    SUBCASE("Soustraction valeurs positives") {
        Fixed result = a - b;
        CHECK(result.toFloat() == doctest::Approx(7.5f).epsilon(0.01));
    }

    SUBCASE("Soustraction resultant negatif") {
        Fixed result = b - a;
        CHECK(result.toFloat() == doctest::Approx(-7.5f).epsilon(0.01));
    }

    SUBCASE("Soustraction avec negatif") {
        Fixed result = a - c;
        CHECK(result.toFloat() == doctest::Approx(15.75f).epsilon(0.01));
    }

    SUBCASE("Soustraction avec zero") {
        Fixed result = a - zero;
        CHECK(result == a);
    }
}

TEST_CASE("Operateur *") {
    Fixed a(10.5f);
    Fixed b(3.0f);
    Fixed c(-5.25f);
    Fixed zero(0);

    SUBCASE("Multiplication valeurs positives") {
        Fixed result = a * b;
        CHECK(result.toFloat() == doctest::Approx(31.5f).epsilon(0.01));
    }

    SUBCASE("Multiplication avec negatif") {
        Fixed result = a * c;
        CHECK(result.toFloat() == doctest::Approx(-55.125f).epsilon(0.01));
    }

    SUBCASE("Multiplication negatifs entre eux") {
        Fixed result = c * c;
        CHECK(result.toFloat() > 27.0f);
        CHECK(result > zero);
    }

    SUBCASE("Multiplication avec zero") {
        Fixed result = a * zero;
        CHECK(result.toFloat() == 0.0f);
    }
}

TEST_CASE("Operateur /") {
    Fixed a(10.5f);
    Fixed b(3.0f);
    Fixed c(-5.25f);
    Fixed large(100.0f);

    SUBCASE("Division valeurs positives") {
        Fixed result = a / b;
        CHECK(result.toFloat() == doctest::Approx(3.5f).epsilon(0.01));
    }

    SUBCASE("Division resultant decimal") {
        Fixed result = b / a;
        CHECK(result.toFloat() == doctest::Approx(0.2857f).epsilon(0.01));
    }

    SUBCASE("Division avec negatif") {
        Fixed result = c / b;
        CHECK(result.toFloat() == doctest::Approx(-1.75f).epsilon(0.01));
    }

    SUBCASE("Division negatifs entre eux") {
        Fixed result = c / c;
        CHECK(result.toFloat() == doctest::Approx(1.0f).epsilon(0.01));
    }

    SUBCASE("Division par grand nombre") {
        Fixed result = b / large;
        CHECK(result.toFloat() == doctest::Approx(0.03f).epsilon(0.01));
    }
}

// ========================================
// TESTS DES CAS LIMITES
// ========================================

TEST_CASE("Operations avec zero") {
    Fixed zero(0);
    Fixed a(42.5f);
    Fixed neg(-10.2f);

    SUBCASE("Comparaisons avec zero") {
        CHECK(zero == Fixed(0));
        CHECK(a > zero);
        CHECK(neg < zero);
        CHECK(zero >= zero);
        CHECK(zero <= zero);
    }

    SUBCASE("Addition avec zero") {
        CHECK((a + zero) == a);
        CHECK((zero + a) == a);
        CHECK((zero + zero) == zero);
    }

    SUBCASE("Soustraction avec zero") {
        CHECK((a - zero) == a);
        CHECK((zero - zero) == zero);
    }

    SUBCASE("Multiplication par zero") {
        CHECK((a * zero).toFloat() == 0.0f);
        CHECK((zero * a).toFloat() == 0.0f);
        CHECK((zero * zero).toFloat() == 0.0f);
    }
}

TEST_CASE("Valeurs negatives") {
    Fixed neg1(-42.5f);
    Fixed neg2(-10.2f);
    Fixed pos(5.0f);
    Fixed zero(0);

    SUBCASE("Addition de negatifs") {
        Fixed result = neg1 + neg2;
        CHECK(result < zero);
        CHECK(result.toFloat() == doctest::Approx(-52.7f).epsilon(0.01));
    }

    SUBCASE("Multiplication negatif * positif") {
        Fixed result = neg1 * pos;
        CHECK(result < zero);
    }

    SUBCASE("Multiplication negatif * negatif") {
        Fixed result = neg1 * neg2;
        CHECK(result > zero);
    }

    SUBCASE("Division avec negatifs") {
        Fixed result1 = neg1 / pos;
        CHECK(result1 < zero);

        Fixed result2 = neg1 / neg2;
        CHECK(result2 > zero);
    }
}

TEST_CASE("Petites et grandes valeurs") {
    Fixed small(0.01f);
    Fixed large(1000.5f);
    Fixed zero(0);

    SUBCASE("Petites valeurs") {
        CHECK(small > zero);
        CHECK(small != zero);
        CHECK(small + small > small);
    }

    SUBCASE("Grandes valeurs") {
        CHECK(large > small);
        CHECK(large - small < large);
        CHECK(large + small > large);
    }

    SUBCASE("Melange petites et grandes") {
        Fixed result = large + small;
        CHECK(result > large);

        Fixed ratio = large / small;
        CHECK(ratio > large);
    }
}

TEST_CASE("Operateur ++")
{
	Fixed	a(5);

	CHECK(a++.toFloat() == 5.0f);
	CHECK(a.toFloat() == 5.0f + 1.0f / 256);
	CHECK((++a).toFloat() == 5.0f + 2.0f / 256);
}

TEST_CASE("Operateur --")
{
	Fixed	a(5);

	CHECK(a--.toFloat() == 5.0f);
	CHECK(a.toFloat() == 5.0f - 1.0f / 256);
	CHECK((--a).toFloat() == 5.0f - 2.0f / 256);
}

TEST_CASE("Min")
{
	Fixed	a(5);
	Fixed	b(1);

	CHECK(Fixed::min(a, b) == b);
	CHECK(Fixed::min(b, a) == b);
}

TEST_CASE("Max")
{
	Fixed	a(5);
	Fixed	b(1);

	CHECK(Fixed::max(a, b) == a);
	CHECK(Fixed::max(b, a) == a);
}
