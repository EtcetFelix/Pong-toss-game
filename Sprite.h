#pragma once

#include "TexRect.h"
#include <iostream>

class Sprite: public TexRect{
    int rows;
    int cols;

    float xinc;
    float yinc;

    int curr_row;
    int curr_col;

    float left;
    float right;
    float top;
    float bottom;

    int lastRow;
    int lastCol;

public:
    Sprite(const char* filename, int rows, int cols, float x, float y, float w, float h): TexRect(filename, x, y, w, h) {
        this->rows = rows;
        this->cols = cols;

        xinc = 1.0 / cols;
        yinc = 1.0 / rows;

        curr_row = 1;
        curr_col = 1;

        this->left = xinc * (curr_col - 1);
        this->right = xinc * curr_col;
        this->top = 1 - yinc * (curr_row - 1);
        this->bottom = 1 - yinc * curr_row;

        lastCol = cols;
        lastRow = rows;
    }

    void draw(float z=0) {
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);
        
        glBegin(GL_QUADS);
        glColor4f(1, 1, 1, 1);
        glTexCoord2f(left, bottom);
        glVertex3f(x, y - h, z);
        
        glTexCoord2f(left, top);
        glVertex3f(x, y, z);
        
        glTexCoord2f(right, top);
        glVertex3f(x+w, y, z);
        
        glTexCoord2f(right, bottom);
        glVertex3f(x+w, y - h, z);
        
        glEnd();
        
        glDisable(GL_TEXTURE_2D);
    }

    void advance() {
        if(curr_col == lastCol && curr_row == lastRow) {
            curr_col = 1;
            curr_row = 1;
        }
        else if(curr_col < cols) {
            curr_col++;
        }
        else {
            if (curr_row < rows) {
                curr_col = 1;
                curr_row++;
            }
            else{
                curr_col = 1;
                curr_row = 1;
            }
        }
        this->left = xinc * (curr_col - 1);
        this->right = xinc * curr_col;
        this->top = 1 - yinc * (curr_row - 1);
        this->bottom = 1 - yinc * curr_row;
    }

    void setSprite(int col, int row) {
        curr_col = col;
        curr_row = row;
        this->left = xinc * (curr_col - 1);
        this->right = xinc * curr_col;
        this->top = 1 - yinc * (curr_row - 1);
        this->bottom = 1 - yinc * curr_row;
    }

    void setX(float x) {
        this->x=x;
    }
    void setY(float y) {
        this->y=y;
    }

    float getX() {return x;}
    float getY() {return y;}
    int getCurrCol() {return curr_col;}
    int getCurrRow() {return curr_row;}

    void setEndSprite(int col, int row) {
        lastCol = col;
        lastRow = row;
    }

    bool reachedLastSprite() {
        if (curr_col==lastCol && curr_row == lastRow) {
            return true;
        }
        else{
            return false;
        }
    }

};