/************************************************************************
  			datatype.h - Copyright enrique
**************************************************************************/

#ifndef DATATYPE_H
#define DATATYPE_H

#include <string>
using namespace std;

/**
 * Class dataType
 * This is an abstract data type of which several data
 * entities may link. 
 * It should be the main parent of any data type that is
 * created thereafter. Some examples should be provided
 * 
 */
class dataType {
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
   string type;
   string description;
   string dtemplate;
  /**
   * 
   */
  /**
   * Accessor Methods
   */
  /**
   * 
   */
  string get_type ( );
    
  
  /**
   * 
   */
  void set_type (string value );
    
  
  /**
   * 
   */
  string get_description ( );
    
  
  /**
   * 
   */
  void set_description (string value );
    
  
  /**
   * 
   */
  string get_template ( );
    
  
  /**
   * 
   */
  void set_template (string value );
    
  
};
#endif //DATATYPE_H

