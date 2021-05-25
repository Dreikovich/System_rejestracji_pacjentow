#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
using namespace std;

#define DELETE_KEY 8;//8
#define ENTER_KEY 13;//13
#define ESKAPE_KEY 27;//27

class Textbox
{
    public :
        Textbox(){}

        Textbox(int size, Color color, bool sel)
        {
            textbox.setCharacterSize(size);
            textbox.setFillColor(color);
            isSelected = sel;
            if(isSelected)
            {
                textbox.setString("_");
            }
            else 
            {
                textbox.setString("");
            }
        }

        void setFont(Font &font)
        {
            textbox.setFont(font);
        }

        void setPosition(Vector2f pos)
        {
            textbox.setPosition(pos);
        }

        void setLimit(bool TrueorFalse, int lim)
        {
            hasLimit = TrueorFalse;
            limit = lim;
        }

        void setSelected(bool sel)
        {
            isSelected = sel;
            if(!sel)
            {
                string t = text.str();
                string newT = "";
                for(int i=0;i<t.length()-1;i++)
                {
                    newT+=t[i];
                }
                textbox.setString(newT);
            }
        }
        
        string getText()
        {
            return text.str();
        }

        void drawTo(RenderWindow &window)
        {
            window.draw(textbox);
        }

        void typedOn(Event input)
        {
            if (isSelected) 
            {
                int charTyped = input.text.unicode;
                if (charTyped < 128) 
                {
                    if (hasLimit) 
                    {
                        // If there's a limit, don't go over it:
                        if (text.str().length() <= limit) 
                        {
                            inputLogic(charTyped);
                        }
                        // But allow for char deletions:
                        else if (text.str().length() > limit && charTyped ==8) 
                        {
                            deleteLastChar();
                        }
                    }
                    // If no limit exists, just run the function:
                    else 
                    {
                        inputLogic(charTyped);
                    }
                }
            }
        }
        void deleteText()
        {
            string newT = "";
            text.str("");
            text<<newT;
            textbox.setString(text.str()+"_");
        }

    private :
        Text textbox;
        ostringstream text;
        bool isSelected=false;
        bool hasLimit=false;
        int limit;

        void inputLogic(int charTyped)
        {
            if((charTyped!=8) && (charTyped!=13) && charTyped!=27)
            {
                text<< static_cast<char>(charTyped);
            }
            else if(charTyped==8)
            {
                if(text.str().length()>0)
                {
                    deleteLastChar();
                }
            }
            textbox.setString(text.str()+"_");
        }

        void deleteLastChar()
        {
            string t = text.str();
            string newT = "";
            for(int i=0;i<t.length()-1;i++)
            {
                newT+=t[i];
            }
            text.str("");
            text<<newT;

            textbox.setString(text.str());
        }

        
};