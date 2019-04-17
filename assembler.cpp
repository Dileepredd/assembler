#include<bits/stdc++.h>
#include<list>
#include<unordered_map>
using namespace std;
int main()
{
  char str[30];
  list<string> instructions;
  unordered_map<string,string> regref = {
  { "$0", "00000" },
  { "$at", "00001" },
  { "$v0", "00010" },
  { "$v1", "00011" },
  { "$a0", "00100" },
  { "$a1", "00101" },
  { "$a2", "00110" },
  { "$a3", "00111" },
  { "$t0", "01000" },
  { "$t1", "01001" },
  { "$t2", "01010" },
  { "$t3", "01011" },
  { "$t4", "01100" },
  { "$t5", "01101" },
  { "$t6", "01110" },
  { "$t7", "01111" },
  { "$s0", "10000" },
  { "$s1", "10001" },
  { "$s2", "10010" },
  { "$s3", "10011" },
  { "$s4", "10100" },
  { "$s5", "10101" },
  { "$s6", "10110" },
  { "$s7", "10111" },
  { "$t8", "11000" },
  { "$t9", "11001" },
  { "$k0", "11010" },
  { "$k1", "11011" },
  { "$gp", "11100" },
  { "$sp", "11101" },
  { "$s8", "11110" },
  { "$ra", "11111" }
  };
  unordered_map<string,string> rtypefunc = {
    { "add", "100000" },
    { "addu", "100001" },
		{ "sub", "100010" },
    { "subu", "100011" },
		{ "and", "100100" },
		{ "or",  "100101" },
		{ "sll", "000000" },
		{ "slt", "101010" },
		{ "srl", "000010" },
		{ "jr",  "001000" },
    { "mult", "011000" },
    { "multu", "011001" },
    { "div", "011010" },
    { "divu", "011011" },
    { "mfhi", "010000" },
    { "mflo", "010010" }
  };
  unordered_map<string,string> itypeop = {
    { "lw", "100011" },
    { "sb", "101000" },
    { "sw", "101011" },
    { "lb", "100000" },
    //{ "la", "404" },
    { "lui", "001111" },
    { "beq", "000100" },
    { "bne", "000101" },
    { "lw", "100011" }
  };
  unordered_map<string,string> jtypeop = {
    { "j", "000010" },
    { "jal", "000011" }
  };
//if required go for unordered maps to store instructions.
  FILE *fp = fopen("q1.s","r");
  while(fgets(str,30,fp) != NULL)
  {
    instructions.push_back(str);
  }
  fclose(fp);
  fp = fopen("q1.txt","w");
  for(auto it = instructions.begin();it!=instructions.end();it++)
  {
    char result[33];
    char instruct[10];
    char reg[4];
    int reg_ = 0;
    int i=0;
    int j = 0;
    int k = 0;
    while((*it)[i] != ' ')
    {
      instruct[j] = (*it)[i];
      i++;
      j++;
    }
    i++;
    instruct[j] = '\0';
    if(rtypefunc.find(instruct) != rtypefunc.end())
    {
      for(;k<6;k++)
      {
        result[k] = '0';
      }
      int temp = 26;
      string x = rtypefunc[instruct];
      int x_ = 0;
      for(;temp<32;temp++)
      {
        result[temp] = x[x_];
        x_++;
      }
      if(instruct == "sll" || instruct == "srl")
      {
        /*temp = 21;
        for(;temp<26;temp++)
        {
          result[temp] = '0';
        }*/
        while((*it)[i] != ',')
        {
          reg[reg_] = (*it)[i];
          i++;
          reg_++;
        }
        i++;
        reg[reg_] = '\0';
        reg_ = 0;
        x = regref[reg];
        x_ = 0;
        for(;k<11;k++)
        {
          result[k] = x[x_];
          x_++;
        }
        for(;k<16;k++)
        {
          result[k] = '0';
        }
        while((*it)[i] != ',')
        {
          reg[reg_] = (*it)[i];
          i++;
          reg_++;
        }
        i++;
        reg[reg_] = '\0';
        reg_ = 0;
        x = regref[reg];
        x_ = 0;
        for(;k<21;k++)
        {
          result[k] = x[x_];
          x_++;
        }
        //shampt read
      }
      else
      {
        temp = 21;
        for(;temp<26;temp++)
        {
          result[temp] = '0';
        }
        while((*it)[i] != ',')
        {
          reg[reg_] = (*it)[i];
          i++;
          reg_++;
        }
        i++;
        reg[reg_] = '\0';
        reg_ = 0;
        x = regref[reg];
        x_ = 0;
        for(;k<11;k++)
        {
          result[k] = x[x_];
          x_++;
        }
        while((*it)[i] != ',')
        {
          reg[reg_] = (*it)[i];
          i++;
          reg_++;
        }
        i++;
        reg[reg_] = '\0';
        reg_ = 0;
        x = regref[reg];
        x_ = 0;
        for(;k<16;k++)
        {
          result[k] = x[x_];
          x_++;
        }
        while((*it)[i] != '\n')
        {
          reg[reg_] = (*it)[i];
          i++;
          reg_++;
        }
        i++;
        reg[reg_ - 1] = '\0';
        reg_ = 0;
        x = regref[reg];
        x_ = 0;
        for(;k<21;k++)
        {
          result[k] = x[x_];
          x_++;
        }
      }
      result[32] = '\n';
      cout<<*it;
      cout<<result<<endl;
      fputs(result,fp);
    }
  }
  fclose(fp);
  return 0;
}
