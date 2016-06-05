/* the catalog table */

#define CAT_CAT_LEN     30
#define CAT_TITLE_LEN   70
#define CAT_TYPE_LEN    30
#define CAT_ATRIST_LEN  70


typedef struct {
	char catalog[CAT_CAT_LEN + 1];
	char title[CAT_TITLE_LEN + 1];
	char type[CAT_TYPE_LEN + 1];
	char artist[CAT_ARTIST_LEN + 1];
} cdc_entry;


/* the tracks table, one entry per track */
#define TRACK_CAT_LEN   CAT_CAT_LEN
#define TRACK_TTEXT_LEN 70

typedef struct {
	char catalog[TRACK_CAT_LEN + 1];
	int track_no;
	char track_txt[TRACK_TTEXT_LEN + 1];
} cdc_entry;


/* Initialization and termination functions */
int database__initialize(const int new_database);
void database_close(void);

/* two for simple data retrieval */
cdc_entry get_cdc_entry(const char *cd_catalog_ptr);
cdt_entry get_cdt_entry(const char *cd_catalog_ptr, const int track_no);

/* two for data addition */
int add_cdc_entry(const cdc_entry entry_to_add);
int add_cdt_entry(const cdt_entry entry_to_add);

/* two for data deletion */
int del_cdc_entry(const char *cd_catalog_ptr);
int del_cdt_entry(const char *cd_catalog_ptr, const int track_no);

/* one serch function */
cdc_entry search_cdc_entry(const char *cd_catalog_ptr, int *first_call_ptr);



