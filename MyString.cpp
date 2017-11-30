//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"


MyString::MyString()
{

}

/*!
 * Constructor 
 * @param receives character
 */
MyString::MyString(const char *character)
{
    int index = 1;
    while(character[index] != '\0')
    {
        index++;
    }
    nlength = index;
   if(nlength > 1)
   {
       internalCString = make_unique<char[]>(nlength);
        index = 0;
        while (character[index] != '\0')
        {
            internalCString[index] = character[index];
            index++;
        }
        index = 0;
        while (internalCString[index] != '\0')
        {
            index++;
        }
   }
    else
   {
       internalCString = make_unique<char[]>(1);
       internalCString = nullptr;
   }
} // end constructor

/*!
 * Get the internal cstring
 * @return internalCString
 */
char *MyString::getInternalCString() const
{
    return internalCString.get();
}// end getInternalCString

/*!
 * compares unique pointers of characters
 * @param lhs
 * @param rhs
 * @return a number that is the result of the comparison
 */
int MyString::compareStr(const MyString &lhs, const MyString &rhs)
{
    int index=0;
    while(lhs.internalCString[index] != '\0' && rhs.internalCString[index] != '\0')
    {
        if(lhs.internalCString[index] < rhs.internalCString[index])
        {
            if(lhs.nlength == rhs.nlength)
                return -2;
            return 1;
        }
        else if(lhs.internalCString[index] > rhs.internalCString[index])
        {
            if(lhs.nlength == rhs.nlength)
                return -2;
            return -1;
        }
        if(lhs.nlength == (index +1) && rhs.nlength == (index +1))
        {
            return 0;
        }
        index++;
    }
    if(lhs.internalCString[index] == '\0' && rhs.internalCString[index] != '\0')
        return -1;
    if(rhs.internalCString[index] == '\0' && lhs.internalCString[index] != '\0')
        return 1;
    return 0;
}// end compareStr

/*!
 * Reverses a unique pointer of characters
 */
void MyString::reverseit()
{
    char temporary;
    int cont = nlength-1;
    int size = nlength;
    for(int i = 0; i < cont; i++)
    {
        temporary = internalCString[cont];
        internalCString[cont] = internalCString[i];
        internalCString[i] = temporary;
        cont--;
    }
    int val = 0;
    internalCString[nlength] = '\0';
}// end reverseit

/*!
 * ovearloas the << operation
 * @param os
 * @param myString
 * @return the message that we want to print
 */
ostream &operator<<(ostream &os, const MyString &myString)
{
    int value = 0;
    while(value < myString.nlength)
    {
        os << myString.internalCString[value];
        value++;
    }
    return os;
}// end operator<<