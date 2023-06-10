#include <iostream>
#include <cstring>
#include <ctime>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

int pass_cnt = 3;

/*
    XML parser correctness test
*/
void subtask1(XMLDocument* doc){
    char decla_test[] = "xml version=\"1.0\" encoding=\"utf-8\"";
    char comment_test[] = "This is a comment";
    char tag_test[] = "bookstore";
    char attr_test[] = "fantasy literature";
    char text_test[] = "J·K·Rowling";
    XMLNode* node = doc->FirstChild();
    if (strcmp(decla_test, node->Value()) != 0) {
        pass_cnt --;
        cout << "subtask1 failed." << endl;
        return;
    }
    node = node->NextSibling();
    if (strcmp(comment_test, node->Value()) != 0) {
        pass_cnt --;
        cout << "subtask1 failed." << endl;
        return;
    }
    node = node->NextSibling();
    if (strcmp(tag_test, node->Value()) != 0) {
        pass_cnt --;
        cout << "subtask1 failed." << endl;
        return;
    }
    XMLElement* ele = node->FirstChildElement();
    if (ele->Attribute("category", attr_test) == 0) {
        pass_cnt --;
        cout << "subtask1 failed." << endl;
        return;
    }
    ele = ele->LastChildElement();
    if (strcmp(text_test, ele->GetText()) != 0) {
        pass_cnt --;
        cout << "subtask1 failed." << endl;
        return ;
    }
    cout << "subtask1 passed." << endl;
}

/*
    XML element modifying test
*/
void subtask2(XMLDocument* doc1){
    char comment_test[] = "That is A comment!";
    char tag_test[] = "BookShop";
    char attr_test[] = "crystal";
    char text_test[] = "excellent";
    XMLNode* node = doc1->FirstChild()->NextSibling();
    node->SetValue(comment_test);
    if (strcmp(comment_test, node->Value()) != 0) {
        pass_cnt --;
        cout << "subtask2 failed." << endl;
        return;
    }
    node = node->NextSibling();
    node->SetValue(tag_test);
    if (strcmp(tag_test, node->Value()) != 0) {
        pass_cnt --;
        cout << "subtask2 failed." << endl;
        return;        
    }
    XMLElement* ele1 = node->FirstChildElement("shelf");
    ele1->SetAttribute("materia", attr_test);
    if (strcmp(attr_test, ele1->Attribute("materia")) != 0) {
        pass_cnt --;
        cout << "subtask2 failed." << endl;
        return;
    }
    ele1 = ele1->FirstChildElement();
    ele1->SetText(text_test);
    if (strcmp(text_test, ele1->GetText()) != 0) {
        pass_cnt --;
        cout << "subtask2 failed." << endl;
        return;
    }
    cout << "subtask2 passed." << endl;
}

/*
    XML output test
*/
void subtask3(XMLDocument* doc1, XMLDocument* doc2){
    clock_t s1 = clock();
    doc1->SaveFile("out.xml");
    clock_t e1 = clock();
    cout << "modified test1.xml saved to out.xml, time cost: " << (double)(e1 - s1) / CLOCKS_PER_SEC << " second." << endl;
    XMLDocument* doc = new XMLDocument();
    clock_t s2 = clock();
    doc->LoadFile("out.xml");
    clock_t e2 = clock();
    cout << "out.xml loaded, time cost: " << (double)(e2 - s2) / CLOCKS_PER_SEC << " second." << endl;
    cout << "============out.xml=============" << endl;
    doc->Print();
    cout << "\n";
    cout << "subtask3 passed." << endl;
}

int main()
{
    XMLDocument* doc1 = new XMLDocument();
    XMLDocument* doc2 = new XMLDocument();
    clock_t s1 = clock();
    doc1->LoadFile("test1.xml");
    clock_t e1 = clock();
    cout << "test1.xml loaded, time cost: " << (double)(e1 - s1) / CLOCKS_PER_SEC << " second." << endl;
    cout << "============test1.xml=============" << endl;
    doc1->Print();
    cout << "\n";
    clock_t s2 = clock();
    doc2->LoadFile("test2.xml");
    clock_t e2 = clock();
    cout << "test2.xml loaded, time cost: " << (double)(e2 - s2) / CLOCKS_PER_SEC << " second." << endl;
    cout << "============test2.xml=============" << endl;
    doc2->Print();
    cout << "\n";
    cout << "============start testing=============" << endl;
    subtask1(doc1);
    subtask2(doc1);
    subtask3(doc1, doc2);
    cout << "============testing ended=============" << endl;
    cout << pass_cnt << " subtask(s) passed, " << 3 - pass_cnt << " subtask(s) failed." << endl;
    return 0;
}