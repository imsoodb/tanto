/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../tanto.h"

/* 
 * read jsno file, parse and print 
*/
int main(int argc, char* argv[])
{
	char *json_file = "../json/products.json";
	char *stream = NULL;

	if (argc > 1) json_file = argv[1];
	printf("%s: %s\n", "FILE", json_file);

	
	stream = tjson_read_file(json_file);

	TJSON_t *json = NULL;
	TJSON_INIT(&json);

	if (tjson_parse(&json, stream) < 0) printf("%s: %s\n", "ERROR! while parsing file", json_file);
	else tjson_print(json);

	//if (json != NULL) tjson_erase(&json);
	if (stream != NULL) free(stream);

	return 0;
}
