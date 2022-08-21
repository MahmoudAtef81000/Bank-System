#pragma once
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <vector>
using namespace std;
class HelperMethods
{
public:

    //Methods:
    template <class type>
    static int idBinarySearch(vector<type> data, int high, int low, int id) {
        int mid = (high + low) / 2;
        if (high < low) {
            return -1;
        }
        else if (data[mid].getId() == id) {
            return mid;
        }
        else if (high == low) {
            if (data[high].getId() == id) {
                return high;
            }
        }
        else if (data[mid].getId() > id) {
            return idBinarySearch(data, mid - 1, low, id);
        }
        else if (data[mid].getId() < id) {
            return idBinarySearch(data, high, mid + 1, id);
        }
        return -1;
    }
    static bool isNum(string stringNum) {
        if (stringNum == "") {
            system("CLS");
            return false;
        }
        for (int i = 0; i < stringNum.size(); i++) {
            if (!isdigit(stringNum[i])) {
                return false;
            }
        }
        return true;
    }
    static bool isFloatNum(string stringNum) {
        if (stringNum == "") {
            system("CLS");
            return false;
        }
        for (int i = 0; i < stringNum.size(); i++) {
            if (!i || (i == stringNum.size() - 1)) {
                if (!isdigit(stringNum[i])) {
                    return false;
                }
            }
            else {
                if (stringNum[i] == '.') {
                    continue;
                }
                else if (!isdigit(stringNum[i])) {
                    return false;
                }
            }
        }
        return true;
    }


};

