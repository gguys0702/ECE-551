#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
//#include "page.h"
#include "story.h"

 //open each page in a file and put it into pages
  bool Story::openPage(char * filename, int i){
    std::string pagename = std::string(filename) + "//page"+std::to_string(i)+".txt";
    const char * n = pagename.c_str();
    std::ifstream ifs;
    ifs.open(n,std::ifstream::in);
    if(ifs.fail()){
      if(i == 1){
        std::cerr<<"there is no page1.txt";
        exit(EXIT_FAILURE);
      }else{
        return false;
      }
    }
    Page p;
    p.inipage(n); 
    pages.push_back(p); 
    //p.printPage();
    ifs.close();
    return true;
  }
  
  //take the name of a story as input, create an object story, read each page, 
  void Story::openStory(char * filename){
    unsigned i = 1;
    //if the file exist
    bool ifexist;
    ifexist = openPage(filename, i);
    i++;
    while(ifexist){
      ifexist = openPage(filename, i);
      i++;
    }
  }
  
  bool Story::checkValid_4(){
    size_t szpages = pages.size();
    std::vector<int> myarr(szpages,0);
    bool checkwin = false;
    bool checklose = false;
    size_t numofpage = szpages;
    std::vector<Page>::iterator it = pages.begin();
    //check each page
    while(it!=pages.end()){
      //check each option of one page
      for(size_t i = 0; i < it->numofop.size(); i++){
       //check if page is referenced is valid
        if(it->numofop[i] > numofpage || it->numofop[i]<=0){
          std::cout << "invalid numofop checkValid_4" <<std::endl;
          return false;
        }
        myarr[it->numofop[i]-1] = 1;
      }
      //check if there's at least one page is win and lose
      //if(it->getifwin()&&it->getendPage()){
      if(it->ifwin&&it->endPage){
        checkwin = true;
      }
      //if((!it->getifwin())&&it->getendPage()){
      if((!it->ifwin)&&it->endPage){
        checklose = true;
      } 
      ++it;
    }
    //check if all pages are referred
    for(size_t i = 1;i<pages.size();i++){
      if(myarr[i] != 1){
        std::cout << "if all pages are referred "<<i+1<<" checkValid_4" <<std::endl;
        return false;
      }
    }
    return checklose && checkwin;
  }
  
  void Story::ifnum(std::string pagenum){
    for(size_t i=0; i < pagenum.size();i++){
      if(!isdigit(pagenum[i])){
         std::cerr<<"invalid page number 1" << std::endl;
         exit(EXIT_FAILURE);
      }
    }
  }
  
  void Story::display_5(){
    Page curr = pages[0]; 
    curr.printPage();
    while(true){
      std::string input;
      getline(std::cin, input);
      ifnum(input);
      unsigned num = std::stoul(input);
      if(num <=0 || num > curr.option.size()){
        std::cout << "That is not a valid choice, please try again" <<std::endl;
        continue;
      }
      std::string slct_page = curr.option[num-1];
      int curr_num = curr.numoption[slct_page];
      curr = pages[curr_num-1];
      curr.printPage();
      if(curr.endPage){
        //exit(EXIT_SUCCESS);
        return;
      } 
    } 
  }
  
  void Story::setReachP(){
    //std::pair<bool,Page> curr(false,pages[0]);
    reachPage.insert(1);
    //std::cout << pages.size()<<std::endl;
    //check if there is new page reachable
    bool ifchange = 1;
    while(ifchange){
      ifchange = 0;
      std::set<unsigned>::iterator it = reachPage.begin();
      while(it != reachPage.end()){
      //std::cout <<"Page:"<<*it<<std::endl;
        //if this page isn't checked
        Page curr = pages[*it-1];
        for(size_t i = 0; i < curr.numofop.size();i++){
            unsigned p_num = curr.numofop[i];
            if(reachPage.count(p_num)==0){
              //std::cout <<p_num<<std::endl;
              reachPage.insert(p_num);
              ifchange = 1;
            }
          }
          ++it;
      }
    }
  }
  
  void Story::printUnreach(){
    size_t szpages = pages.size();
    //std::cout << pages.size()<<std::endl;
    //check each page
     for(unsigned i = 1;i <= szpages;i++){
     //std::cout << "Page " << i <<" is not reachable"<<std::endl;
      if(reachPage.count(i)!=1){
        std::cout << "Page " << i <<" is not reachable"<<std::endl;
      }
   }
  
  }
  
  void findSucPath(){
    std::set<unsigned>::iterator it=reachPage.begin();
    while(it!=reachPage.end()){
      if(pages[*it-1].getifwin){
        sucPath.insert(std::pair<unsigned,unsigned>(*it,0));
        traceBack(*it);
        return;
      }
    }
  }
  
  void traceBack(unsigned pagenum){
    std::set<unsigned>::iterator it=reachPage.begin();
    while(it!=reachPage.end()){
      std::vector<unsigned> numofop=pages[*it-1].getnumofop);
     // std::set<unsigned>::iterator itofnum=numofop.find(pagenum);
     // if(itofnum!=numofop.end()){
     for(size_t i = 0;i<numofop.size();i++){
       if(numofop[i] == pagenum){
        sucPath.insert(std::pair<unsigned,unsigned>(*it,i+1));
        if(*it != 1){
          traceBack(*it);
        } else{
          return;
        }
       }
      }
    }
  }
  
  
  