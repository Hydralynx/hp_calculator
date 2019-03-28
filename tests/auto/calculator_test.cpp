//#define CATCH_CONFIG_MAIN
#ifndef CATCH_CONFIG_MAIN
//Mettre en commentaire le define pour éviter les conflits de main hors des tests
#else
#include "../inc/test/catch.hpp"
#include "calculator.h"

using namespace std;

TEST_CASE("Test fonction RAZ de la pile", "[Calculator][flushStack]")
{
    Calculator test_calc;

    test_calc.pushNumber(12);
    test_calc.pushNumber(23.5);
    test_calc.pushNumber(-1.345);

    test_calc.flushStack();

    CHECK(test_calc.isInitialized());
}

TEST_CASE("Test fonction d'initialisation", "[Calculator][isInitialized]")
{
    Calculator test_calc;

    test_calc.pushNumber(23);
    test_calc.pushNumber(-31.1234);
    test_calc.pushNumber(1.43);

    test_calc.flushStack();

    CHECK(test_calc.isInitialized());
}

TEST_CASE("Test fonction division", "[Calculator][divide]")
{
    Calculator test_calc;

    REQUIRE(test_calc.isInitialized());

    SECTION("Test avec quotient non nul")
    {
        test_calc.pushNumber(5);
        test_calc.pushNumber(2);
        CHECK(test_calc.divide() == "2.500000");
        test_calc.flushStack();
    }

    SECTION("Test division par 0")
    {
        test_calc.pushNumber(2);
        test_calc.pushNumber(0);
        CHECK(test_calc.divide() == "ERROR");
        test_calc.flushStack();
    }

    SECTION("Test avec pile vide")
    {
        CHECK(test_calc.displayTop() == "ERROR");
    }
}

TEST_CASE("Test fonction multiplication", "[Calculator][multiply]")
{
    Calculator test_calc;

    REQUIRE(test_calc.isInitialized());

    SECTION("Test avec un positif et un négatif")
    {
        test_calc.pushNumber(2.5);
        test_calc.pushNumber(-3);
        CHECK(test_calc.multiply() == "-7.500000");
        test_calc.flushStack();
    }

    SECTION("Test avec pile vide")
    {
        CHECK(test_calc.displayTop() == "ERROR");
    }
}

TEST_CASE("Test fonction addition", "[Calculator][add]")
{
    Calculator test_calc;

    REQUIRE(test_calc.isInitialized());

    SECTION("Test avec un positif et un négatif")
    {
        test_calc.pushNumber(2.5);
        test_calc.pushNumber(-3);
        CHECK(test_calc.add() == "-0.500000");
        test_calc.flushStack();
    }

    SECTION("Test avec pile vide")
    {
        CHECK(test_calc.displayTop() == "ERROR");
    }
}

TEST_CASE("Test fonction soustraction", "[Calculator][substract]")
{
    Calculator test_calc;

    REQUIRE(test_calc.isInitialized());

    SECTION("Test avec un positif et un négatif")
    {
        test_calc.pushNumber(2.5);
        test_calc.pushNumber(-3);
        CHECK(test_calc.substract() == "5.500000");
        test_calc.flushStack();
    }

    SECTION("Test avec deux négatifs")
    {
        test_calc.pushNumber(-2.5);
        test_calc.pushNumber(-3);
        CHECK(test_calc.substract() == "0.500000");
        test_calc.flushStack();
    }

    SECTION("Test avec pile vide")
    {
        CHECK(test_calc.displayTop() == "ERROR");
    }
}

TEST_CASE("Test fonction carré", "[Calculator][square]")
{
    Calculator test_calc;

    REQUIRE(test_calc.isInitialized());

    SECTION("Test avec un positif décimal")
    {
        test_calc.pushNumber(2.5);
        CHECK(test_calc.square() == "6.250000");
        test_calc.flushStack();
    }

    SECTION("Test avec un négatif décimal")
    {
        test_calc.pushNumber(-2.5);
        CHECK(test_calc.square() == "6.250000");
        test_calc.flushStack();
    }

    SECTION("Test avec pile vide")
    {
        CHECK(test_calc.displayTop() == "ERROR");
    }
}

TEST_CASE("Test fonction rappel", "[Calculator][displayTop")
{
    Calculator test_calc;

    REQUIRE (test_calc.isInitialized());

    SECTION("Test avec valeurs")
    {
        test_calc.pushNumber(34.6);
        CHECK(test_calc.displayTop() == "34.600000");
        test_calc.flushStack();
    }

    SECTION("Test avec pile vide")
    {
        CHECK(test_calc.displayTop() == "ERROR");
    }
}

TEST_CASE("Test fonction M+", "[Calculator][addToTop]")
{
    Calculator test_calc;

    REQUIRE(test_calc.isInitialized());

    SECTION("Addition du nombre affiché avec le haut de la pile")
    {
        test_calc.pushNumber(2);
        test_calc.addToTop(2);
        CHECK(test_calc.square() == "16.000000");
        test_calc.flushStack();
    }

    SECTION("Essai avec calculs")
    {
        test_calc.pushNumber(-2);
        test_calc.addToTop(3);
        test_calc.pushNumber(6);

        CHECK(test_calc.add() == "7.000000");
    }

    SECTION("Essai avec pile vide")
    {
        CHECK(test_calc.addToTop(2) == "ERROR");
    }
}

TEST_CASE("Simulation de calculs")
{
    Calculator test_calc;

    REQUIRE(test_calc.isInitialized());

    SECTION("Séquence : 2 3 * 4 5 * -")
    {
        test_calc.pushNumber(2);
        test_calc.pushNumber(3);
        test_calc.multiply();
        test_calc.pushNumber(4);
        test_calc.pushNumber(5);
        test_calc.multiply();

        CHECK(test_calc.substract() == "-14.000000");
        test_calc.flushStack();
    }

    SECTION("Séquence : 10 0 2 - *")
    {
        test_calc.pushNumber(10);
        test_calc.pushNumber(0);
        test_calc.pushNumber(2);
        REQUIRE(test_calc.substract() == "-2.000000");
        CHECK(test_calc.multiply() == "-20.000000");
        test_calc.flushStack();
    }

    SECTION("Séquence : 25 8 2 4 12 + * - + 5 /")
    {
        test_calc.pushNumber(25);
        test_calc.pushNumber(8);
        test_calc.pushNumber(2);
        test_calc.pushNumber(4);
        test_calc.pushNumber(12);
        REQUIRE(test_calc.add() == "16.000000");
        REQUIRE(test_calc.multiply() == "32.000000");
        REQUIRE(test_calc.substract() == "-24.000000");
        REQUIRE(test_calc.add() == "1.000000");
        test_calc.pushNumber(5);
        CHECK(test_calc.divide() == "0.200000");
    }
}
#endif
