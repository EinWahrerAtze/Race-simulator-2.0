//
//  Classes.hpp
//  Race_simulator
//
//  Created by Den Fedorov on 07.08.2022.
//
#pragma once
#include <string>
#include "Localization.hpp"

//Abstract base class for units
class units_ABC
{
public:
    units_ABC(const std::string & name = "none", int speed = 0, float result = 0.0f);
    virtual ~units_ABC();
    virtual void calculation(float distance) = 0;
    const std::string & get_name() const;
    float get_result() const;
protected:
    std::string m_name;
    int m_speed;
    float m_result;
};

class Camel : public units_ABC
{
public:
    Camel(const std::string & name = "Camel", int s = 10, int ttr = 30);
    ~Camel();
    void calculation(float distance) override;
private:
    int m_time_till_rest;
};

class Fast_camel : public units_ABC
{
public:
    Fast_camel(const std::string & name = "Fast camel", int s = 40, int ttr = 10);
    ~Fast_camel();
    void calculation(float distance) override;
private:
    int m_time_till_rest;
};

class Centaur : public units_ABC
{
public:
    Centaur(const std::string & name = "Centaur", int s = 15, int ttr = 8);
    Centaur(const Centaur & c);
    const Centaur & operator=(const Centaur & c);
    ~Centaur();
    void calculation(float distance) override;
private:
    int m_time_till_rest;
};

class All_terrain_boots : public units_ABC
{
public:
    All_terrain_boots(const std::string & name = "All terrain boots", int s = 6, int ttr = 60);
    ~All_terrain_boots();
    void calculation(float distance) override;
private:
    int m_time_till_rest;
};

class Magic_carpet : public units_ABC
{
public:
    Magic_carpet(const std::string & name = "Magic carpet", int s = 10, float c = 0.0f);
    ~Magic_carpet();
    void calculation(float distance) override;
private:
    mutable float m_cancellation;
};

class Eagle : public units_ABC
{
public:
    Eagle(const std::string & name = "Eagle", int s = 8, float c = 0.94);
    ~Eagle();
    void calculation(float distance) override;
private:
    float m_cancellation;
};

class Magic_broom : public units_ABC
{
public:
    Magic_broom(const std::string & name = "Magic broom", int s = 20, float c = 0);
    ~Magic_broom();
    void calculation(float distance) override;
private:
    mutable float m_cancellation;
};