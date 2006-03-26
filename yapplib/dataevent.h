/************************************************************************
  			dataevent.h - Copyright enrique

Here you can write a license for your code, some comments or any other
information you want to have in your generated code. To to this simply
configure the "headings" directory in uml to point to a directory
where you have your heading files.

or you can just replace the contents of this file with your own.
If you want to do this, this file is located at

/usr/share/apps/umbrello/headings/heading.h

-->Code Generators searches for heading files based on the file extension
   i.e. it will look for a file name ending in ".h" to include in C++ header
   files, and for a file name ending in ".java" to include in all generated
   java code.
   If you name the file "heading.<extension>", Code Generator will always
   choose this file even if there are other files with the same extension in the
   directory. If you name the file something else, it must be the only one with that
   extension in the directory to guarantee that Code Generator will choose it.

you can use variables in your heading files which are replaced at generation
time. possible variables are : author, date, time, filename and filepath.
just write %variable_name%

This file was generated on lun mar 27 2006 at 00:23:23
The original location of this file is 
**************************************************************************/

#ifndef DATAEVENT_H
#define DATAEVENT_H
#include <string>
#include "dataentity.h"
#include "datatick.h"

class dataEvent {
/**
 * Public stuff
 */
public:
  /**
   * Fields
   */
  /**
   * 
   */
  /**
   * Accessor Methods
   */
/**
 * Protected stuff
 */
protected:
  /**
   * Fields
   */
  /**
   * 
   */
  /**
   * Accessor Methods
   */
/**
 * Private stuff
 */
private:
  /**
   * Fields
   */
   dataEntity evDEntity;
   dataTick data;
  /**
   * Contributor is the Client ID of the original contributor
   */
   string contributor;
  /**
   * 
   */
  /**
   * Accessor Methods
   */
  /**
   * 
   */
  dataEntity get_evDEntity ( );
    
  
  /**
   * 
   */
  void set_evDEntity (dataEntity value );
    
  
  /**
   * 
   */
  dataTick get_data ( );
    
  
  /**
   * 
   */
  void set_data (dataTick value );
    
  
  /**
   * Get the value of contributor
   * Contributor is the Client ID of the original contributor
   * @return the value of contributor
   */
  string get_contributor ( );
    
  
  /**
   * Set the value of contributor
   * Contributor is the Client ID of the original contributor
   * @param value the value of contributor
   */
  void set_contributor (string value );
    
  
};
#endif //DATAEVENT_H

