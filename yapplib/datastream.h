/************************************************************************
  			datastream.h - Copyright enrique

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

This file was generated on lun mar 27 2006 at 00:23:50
The original location of this file is 
**************************************************************************/

#ifndef DATASTREAM_H
#define DATASTREAM_H
#include <string>
#include "datatick.h"

class dataStream {
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
   * Operations
   */
  /**
   * Injects data to the stream and cascades to the network
   * if there are subscribers.
   */
  int  injectData (dataTick tick);
    
  
  /**
   * Reads more data from this stream.
   * 
   */
  int  readData ();
    
  
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
   * Operations
   */
/**
 * Private stuff
 */
private:
  /**
   * Fields
   */
  /**
   * This is the last tick that this stream has received or injected.
   */
   dataTick lstTick;
  /**
   * Determines if the data is to be stored as it is read or contributed to the network
   */
   int storable;
  /**
   * 
   */
  /**
   * Accessor Methods
   */
  /**
   * Get the value of lstTick
   * This is the last tick that this stream has received or injected.
   * @return the value of lstTick
   */
  dataTick get_lstTick ( );
    
  
  /**
   * Set the value of lstTick
   * This is the last tick that this stream has received or injected.
   * @param value the value of lstTick
   */
  void set_lstTick (dataTick value );
    
  
  /**
   * Get the value of storable
   * Determines if the data is to be stored as it is read or contributed to the network
   * @return the value of storable
   */
  int get_storable ( );
    
  
  /**
   * Set the value of storable
   * Determines if the data is to be stored as it is read or contributed to the network
   * @param value the value of storable
   */
  void set_storable (int value );
    
  
  /**
   * Operations
   */
};
#endif //DATASTREAM_H

