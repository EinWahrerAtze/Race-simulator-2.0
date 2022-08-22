//
//  Localization.hpp
//  Race_simulator
//
//  Created by Den Fedorov on 08.08.2022.
//

#pragma once
#include <vector>
#include "Classes.hpp"

class units_ABC;

class Localization
{
public:
    enum Lang
    {
        eng,
        rus
    };
    void greeting() const;
    void menu() const;
    void get_distance() const;
    void selected_units(const std::vector<units_ABC *> & ptrs, int n, float d) const;
    void units_list(std::vector<units_ABC *> & ptrs, size_t index) const;
    void out_of_range() const;
    void race_warning() const;
    void wrong_input() const;
    void race_result(const std::vector<units_ABC *> & ptrs) const;
    void ask_restart() const;
    void farewell() const;
    void change_language();
    const Lang & get_lang() const;
    Localization(Lang = Lang::eng);
    ~Localization();
private:
    Lang m_lang;
};