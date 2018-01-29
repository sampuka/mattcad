#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H

#include <string>

//Meant to only be one instance of. Used to contain settings and objects that should only be one of, fx sf::Font
class GlobalSettings
{
public:
    GlobalSettings();
    ~GlobalSettings();

    void setFont(std::string fontname);
    sf::Font* getFont();

private:
};

#endif
