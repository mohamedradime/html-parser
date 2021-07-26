
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>


using namespace std;


typedef int short unsigned _ushort;


struct Element {
  string tag = "";
  vector<string> attributes;
  vector<string> value;
  string content;
  vector<Element> children;
};


vector<Element> elements;
vector<_ushort> hierarchy;
Element element;


void parse (string md);
void append ();


int main () {

  _ushort lines_count, queries_count;
  scanf("%hu %hu\n", &lines_count, &queries_count);

  for (_ushort line_index = 0; line_index < lines_count; line_index++) {
    string md;
    getline (cin, md);
    parse (md);
  }

  cout << elements[0].content << ", " << element.tag << endl;

  cin.get();
  return 0;
}



void parse (string md) {

  static vector<string> pending_tags;

  static bool parsed_tag = false;
  static bool in_tag = false;
  static bool completed_tag_name = false;
  static bool in_attribute = false;
  static char quote_type;
  static string current_tag = "";
  
  size_t index = 0;
  while (index < md.length ()) {

    if (!parsed_tag) { // parse the main tag
      size_t tag_start = md.find ('<', index);
      if (!in_tag) {
        // need to check for a new tag
        // need to check for '<' index
        if (tag_start > index) {
          element.content = md.substr (index, tag_start == string::npos ? md.length () : tag_start);
          append ();
        }
        if (tag_start != string::npos) {
          current_tag = '<';
          in_tag = true;
          completed_tag_name = false;
          index = tag_start + 1;
        } else {
          index = tag_start;
        }
        continue;
      } else {
        // check if there is a tag opening before ending of current tag
        size_t tag_end = md.find ('>', index);
        if (tag_start != string::npos && tag_end > tag_start) {
          element = {};
          if (tag_start != 0) current_tag.append (md.substr (index, tag_start - 1));
          element.content.append (current_tag);
          append ();
          in_tag = false;
          index = tag_start;
          continue;
        }
        if (!completed_tag_name) {
          // still need to get tag name
          if (md[index] == ' ') {
            current_tag.append (" ");
            index++;
            continue;
          }
          size_t tag_name_end = md.find (' ', index);
          string current_tag_name = md.substr (index, tag_name_end == string::npos ? md.length () : tag_name_end);
          element.tag.append (current_tag_name);
          current_tag.append (current_tag_name);
          if (tag_name_end != string::npos) {
            completed_tag_name = true;
            in_attribute = false;
          }
          index = tag_name_end == string::npos ? md.length () : tag_name_end + 1;
          continue;
        } else {
          if (!in_attribute) {
            // need to check for a new attribute
            break;
          } else {
            // still need to parse the current attribute
          }
        }
      }
    } else {
      // seeking for the tag end while parsing any children
    }

  }

}


void append () {

  vector<Element> *root_pointer = &elements;

  // check if i need to change the default root element pointer
  if (hierarchy.size () > 0) {
    // change the reference
  }

  vector<Element>& root_element = *root_pointer;


  // check if the current element is a text node and same for the previus element
  if ( element.tag.empty () && ( !root_element.empty () && root_element.back().tag.empty () ) ) {
    root_element.back ().content.append (element.content);
  } else {
    root_element.push_back (element);
  }

  element = {};

}