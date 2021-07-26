
// #include <cstdio>
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;


// typedef int unsigned _uint;
// typedef int short unsigned _ushort;

// typedef vector<Element> _elements;
// typedef vector<string> _strings;


// struct Element {
//   string tag;
//   _strings attributes;
//   _strings value;
//   string content;
//   _elements children;
// };


// void parse (string *md, _elements *elements, string *current_tag, _strings *pending_tags);


// int main () {

//   string md;
//   _elements elements;
//   string current_tag;
//   _strings pending_tags;

//   _ushort lines_count, queries_count;
//   scanf("%hu %hu\n", &lines_count, &queries_count);

//   for (_ushort line_index = 0; line_index < lines_count; line_index++) {
//     getline(cin, md);
//     parse(&md, &elements, &current_tag, &pending_tags);
//   }

//   cout << elements[0].content << endl;

//   // cin.get();
//   return 0;
// }


// Element create_text (string text) {
//   struct Element element;
//   element.content = text;
//   return element;
// }

// void parse (string *md_p, _elements *elements_p, string *current_tag_p, _strings *pending_tags_p) {

//   string& md = *md_p;
//   _elements& elements = *elements_p;
//   string& current_tag = *current_tag_p;
//   _strings& pedning_tags = * pending_tags_p;

//   bool in_tag = !current_tag.empty();

//   if (in_tag) {
//     md.append(current_tag);
//   }

//   _uint index = 0;
//   bool finished_tag = false;

//   while (index < md.length()) {
    
//     _uint tag_opening_start = md.find("<");
//     _uint tag_opening_end = md.find(">");
//     _uint tag_opening_start_between = md.find("<", tag_opening_start + 1);

//     if (in_tag && !finished_tag) {

//       if (tag_opening_end > tag_opening_start) {
//         cout << "AFTER ALL THIS! WTF" << endl;
//       }

//       finished_tag = true;

//     } else {

      

//     }

//     break;

//   }

// }