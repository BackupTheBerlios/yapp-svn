/************************************************************************
  			dataentity.h - Copyright enrique

**************************************************************************/

#ifndef DATAENTITY_H
#define DATAENTITY_H
#include <string>
using namespace std;

/**
 * Class dataEntity
 * This is the data Reality to which a data event is linked:
 * consumer price in Germany or Temperature at my place.
 */
class dataEntity {
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
   string deName;
   string deDescription;
   int deLastUpdate;
  /**
   * 
   */
  /**
   * Accessor Methods
   */
  /**
   * 
   */
  string get_deName ( );
    
  
  /**
   * 
   */
  void set_deName (string value );
    
  
  /**
   * 
   */
  string get_deDescription ( );
    
  
  /**
   * 
   */
  void set_deDescription (string value );
    
  
  /**
   * 
   */
  int get_deLastUpdate ( );
    
  
  /**
   * 
   */
  void set_deLastUpdate (int value );
    
  
};
#endif //DATAENTITY_H

