#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

namespace sdds {
	class Station
	{
		int m_id; // the id of the station.
		std::string m_name; // the name of the item handled by the station
		std::string m_desc; // the description of the station
		unsigned int m_serial; // the next serial number to be assigned to an item at this station (non-negative integer).
		unsigned int m_current; // The number of items currently in stock (non-negative integer).

		// Class variables
		static size_t m_widthField; // the maximum number of characters required to print to the screen the item name, sn and quant. Initial value is 0.
		static int id_generator; // variable used to generate IDs for new instances of Station.
	public:
		Station(const std::string&); // Custom 1 argument constructor
		const std::string& getItemName() const; // Returns the name of the current Station.
		unsigned int getNextSerialNumber(); // returns the next sn.
		unsigned int getQuantity() const; // returns remaining qty.
		void updateQuantity(); // subtracts 1 from avail qty; should not drop below 0.
		void display(std::ostream& os, bool full) const;
	};
}
#endif