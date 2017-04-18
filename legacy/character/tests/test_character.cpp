/**
 * @file legacy/tests/character/test_character.cpp
 * @brief Tests for the Legacy character submodule.
 */

/*
 * Copyright 2017 Stephen M. Webb <stephen.webb@bregmasoft.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "legacy/character/character.h"
#include "legacy/character/characterbuilder.h"
#include "legacy/character/sexualityconfig.h"
#include "legacy/core/random.h"


using Legacy::Character::CharacterBuilder;
using Legacy::Character::Sexuality;


class FakeCharacterBuilder
: public CharacterBuilder
{
  std::string
  choose_given_name(Sexuality::Gender) override
  { return "Jethro"; }

  std::string
  choose_surname(Sexuality::Gender) override
  { return "Smith"; }

  Legacy::Character::Sexuality
  choose_sexuality() override
  {
    Legacy::Core::RandomNumberGenerator rng;
    Legacy::Character::SexualityConfig config;
    return Sexuality::generate(config, rng);
  }

};


SCENARIO("A basic instatiation of a charcter object.")
{
  GIVEN("A character builder object")
  {
    FakeCharacterBuilder builder;

    WHEN("a character is constructed")
    {
      Legacy::Character::Character character(builder);
      THEN("it succeeds")
      {
        CHECK(character.age() >= 18);
        CHECK(character.given_name().length() > 0);
        CHECK(character.surname().length() > 0);
      }
    }
  }
}
