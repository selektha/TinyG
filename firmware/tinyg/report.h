/*
 * report.h - TinyG status report and other reporting functions
 * Part of TinyG project
 *
 * Copyright (c) 2010 - 2013 Alden S. Hart Jr.
 *
 * TinyG is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 *
 * TinyG is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with TinyG  If not, see <http://www.gnu.org/licenses/>.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef report_h
#define report_h

char *rpt_get_status_message(uint8_t status, char *msg);
void rpt_print_message(char *msg);
void rpt_exception(uint8_t status, int16_t value);
void rpt_print_loading_configs_message(void);
void rpt_print_initializing_message(void);
void rpt_print_system_ready_message(void);

void rpt_init_status_report(void);
uint8_t rpt_set_status_report(cmdObj_t *cmd);
void rpt_decr_status_report(void);
void rpt_request_status_report(void);
void rpt_status_report_rtc_callback(void);
uint8_t rpt_status_report_callback(void);
void rpt_run_text_status_report(void);
void rpt_populate_unfiltered_status_report(void);
uint8_t rpt_populate_filtered_status_report(void);

void rpt_request_queue_report(void);
uint8_t rpt_queue_report_callback(void);

// If you are looking for the defaults for the status report see config.h

/* unit test setup */
//#define __UNIT_TEST_REPORT	// uncomment to enable report unit tests
#ifdef __UNIT_TEST_REPORT
void sr_unit_tests(void);
#define	REPORT_UNITS sr_unit_tests();
#else
#define	REPORT_UNITS
#endif // __UNIT_TEST_REPORT

#endif

