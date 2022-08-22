//
//  Land.cpp
//  Race_simulator
//
//  Created by Den Fedorov on 07.08.2022.
//

#include <iostream>
#include <cmath>
#include "Classes.hpp"

units_ABC::units_ABC(const std::string & s, int speed, float result) : m_name(s)
{
    m_speed = speed;
    m_result = result;
}

const std::string & units_ABC::get_name() const
{
    return m_name;
}

float units_ABC::get_result() const
{
    return m_result;
}

units_ABC::~units_ABC()
{
}

//--------------------------------------------------------------------------------------------------

Camel::Camel(const std::string & s, int speed, int time) : units_ABC(s, speed)
{
    m_time_till_rest = time;
}

Camel::~Camel()
{
}

void Camel::calculation(float distance)
{
    float race = m_speed * m_time_till_rest;

    if (race > distance)
    {
        m_result = distance / m_speed;
    }
    else
    {
        unsigned int stops = static_cast<int>(distance / race);
        m_result = distance / m_speed;
        m_result += (stops - 1) * 8 + 5;
    }
}

//--------------------------------------------------------------------------------------------------

Fast_camel::Fast_camel(const std::string & s, int speed, int time) : units_ABC(s, speed)
{
    m_time_till_rest = time;
}

Fast_camel::~Fast_camel()
{
}

void Fast_camel::calculation(float distance)
{
    float race = m_speed * m_time_till_rest;

    if (race > distance)
    {
        m_result = distance / m_speed;
    }
    else
    {
        unsigned int stops = static_cast<int>(distance / race);
        m_result = distance / m_speed;
        m_result += 5;

        if (stops > 1)
        {
            m_result += 6.5;
            m_result += (stops - 2) * 8;
        }
    }
}

//--------------------------------------------------------------------------------------------------

Centaur::Centaur(const std::string & s, int speed, int time) : units_ABC(s, speed)
{
    m_time_till_rest = time;
}

Centaur::~Centaur()
{
}

void Centaur::calculation(float distance)
{
    float race = m_speed * m_time_till_rest;

    if (race > distance)
    {
        m_result = distance / m_speed;
    }
    else
    {
        unsigned int stops = static_cast<int>(distance / race);
        m_result = distance / m_speed;
        m_result += stops * 2;
    }
}

//--------------------------------------------------------------------------------------------------

All_terrain_boots::All_terrain_boots(const std::string & s, int speed, int time) : units_ABC(s, speed)
{
    m_time_till_rest = time;
}

All_terrain_boots::~All_terrain_boots()
{
}

void All_terrain_boots::calculation(float distance)
{
    float race = m_speed * m_time_till_rest;

    if (race > distance)
    {
        m_result = distance / m_speed;
    }
    else
    {
        unsigned int stops = static_cast<int>(distance / race);
        m_result = distance / m_speed;
        m_result += (stops - 1) * 5 + 10;
    }
}

//--------------------------------------------------------------------------------------------------

Magic_carpet::Magic_carpet(const std::string & s, int speed, float cancellation) : units_ABC(s, speed)
{
    m_cancellation = cancellation;
}

Magic_carpet::~Magic_carpet()
{
}

void Magic_carpet::calculation(float distance)
{
    if (distance >= 1000 && distance < 5000)
    {
        m_cancellation = 0.97f;
    }
    if (distance >= 5000 && distance < 10000)
    {
        m_cancellation = 0.90f;
    }
    if (distance >= 10000)
    {
        m_cancellation = 0.95f;
    }

    distance *= m_cancellation;
    m_result = distance / m_speed;
}

//--------------------------------------------------------------------------------------------------

Eagle::Eagle(const std::string & s, int speed, float cancellation) : units_ABC(s, speed)
{
    m_cancellation = cancellation;
}

Eagle::~Eagle()
{
}

void Eagle::calculation(float distance)
{
    distance *= m_cancellation;
    m_result = distance / m_speed;
}

//--------------------------------------------------------------------------------------------------

Magic_broom::Magic_broom(const std::string & s, int speed, float cancellation) : units_ABC(s, speed)
{
    m_cancellation = cancellation;
}

Magic_broom::~Magic_broom()
{
}

void Magic_broom::calculation(float distance)
{
    m_cancellation = std::floorf(distance / 1000);
    m_cancellation = (100 - m_cancellation) / 100;
    distance *= m_cancellation;
    m_result = distance / m_speed;
}