/*
 * =====================================================================================
 *
 *       Filename:  command.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/2022 21:52:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

using namespace std;

string exec(string command) {
   char buffer[128];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   return result;
}

int main() {
   string ls = exec("ls /usr/bin");
   cout << ls;
}
