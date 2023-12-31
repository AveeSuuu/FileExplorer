#include <iostream>
#include <string>
#include <vector>
#include "PathHandler.hpp"
/*TODO
* before anything else:
* > PLAN MORE STUFF U DUMB FUCK
*
* Classes:
* > Folder, Operations, (for now to test things)
* > File class + text editing later
*
* must-have functions:
* > smth to separate command and parameters/names
* > function that makes use of separated strings above
*
* Tests:
* > add and remove functions (opening for later)
*/

//Would be nice if current path was visible just like in normal terminal


int main() {

  PathHandler path;
  Folder* home = new Folder("home");
  Folder* desktop = new Folder("desktop");
  Folder* documents = new Folder("documents");

  path.addToPath(home);
  path.addToPath(desktop);
  path.addToPath(documents);

  std::cout << path.getPath();

  return 0;
}
