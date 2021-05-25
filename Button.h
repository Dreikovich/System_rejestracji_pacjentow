# pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
    public :
        Button(){ }

        Button(string t, Vector2f size, int charSize,Color bgColor, Color textColor)
        {
            text.setString(t);
            text.setFillColor(textColor);
            text.setCharacterSize(charSize);

            button.setSize(size);
            button.setFillColor(bgColor);
        }

        void setfont(sf::Font &font)
        {
            text.setFont(font);
        }

        void setBackColor(sf::Color color)
        {
            button.setFillColor(color);
        }

        void setTextColor(sf::Color color)
        {
            text.setFillColor(color);
        }

        void setPosition(sf::Vector2f pos)
        {
            button.setPosition(pos);
            float xPos=(pos.x + button.getGlobalBounds().width / 5);
            float yPos=(pos.y + button.getGlobalBounds().height / 3.75);
            text.setPosition({xPos, yPos});
        }

        void drawTo(sf::RenderWindow &window)
        {
            window.draw(button);
            window.draw(text);
        }

        bool isMouseOver(sf::RenderWindow &window)
        {
            float mouseX = sf::Mouse::getPosition(window).x;
            float mouseY = sf::Mouse::getPosition(window).y;

            float btnPosX = button.getPosition().x;
            float btnPosY = button.getPosition().y;

            float btnxPosWidth = button.getPosition().x+button.getLocalBounds().width;
            float btnyPosWidth = button.getPosition().y+button.getLocalBounds().height;

            if(mouseX<btnxPosWidth && mouseX>btnPosX && mouseY<btnyPosWidth && mouseY>btnPosY)
            {
                return true;
            }
            return false;
        }

    private:
        sf::RectangleShape button;
        sf:: Text text;
};