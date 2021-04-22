#ifndef __HEADER__
#define __HEADER__

#define NUM 100000

enum  _status {negative, secondary_contact, primary_contact, positive};
struct __day {
	_person person[NUM];
	_path path;
	_station station[NUM];
};

struct __person {
	_status status;
	int days;
	int cause;
	int station;
};

struct __station {
	_status worst_affected;
	_list list;
    int station_id;
    int weight;
    struct __station* next;
};
struct __list {
	int person_id;
	struct __list* next;
};
struct __path {
	int person_id;
	_route* next_station;
	struct __path* next_person;
};
struct __route {
	int station_id;
	struct __route* next_station;
};
struct Network {
  int total_stations;
  struct __station** adjLists;
};
typedef struct __day _day;
typedef struct __person _person;
typedef struct __station _station;
typedef struct __path _path;
typedef struct __route _route;
typedef struct __list _list;

struct __station* create_station(int);                  //Creates a stn, with station_id as input 
struct Network* createANetwork(int N);                  //Creates a network of N stations
void addEdge(struct Network*, int s, int d , int w );   //Adds an edge of length w between s and d
void printNetwork(struct Network*);                     //Prints the Graph

#endif
