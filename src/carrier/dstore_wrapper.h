/*
 * Copyright (c) 2018 Elastos Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __DSOTRE_WRAPPER_H__
#define __DSOTRE_WRAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ElaCarrier    ElaCarrier;
typedef struct DStoreWrapper DStoreWrapper;

typedef void (*DStoreOnMsgCallback)(ElaCarrier *carrier,
                                    const char *from,
                                    const uint8_t *message, size_t len);

/*
 * Create an dstore wrapper.
 */

DStoreWrapper *dstore_wrapper_create(ElaCarrier *w, DStoreOnMsgCallback cb);

/*
 * Destroy an dstore wrapper
 */
void dstore_wrapper_kill(DStoreWrapper *);

/*
 * Enqueue an message to poll offline message.
 */
void dstore_enqueue_pollmsg(DStoreWrapper *);

/*
 *  Enqueue an message to send offline message aynchronizedly.
 */
int dstore_enqueue_offmsg(DStoreWrapper *, const char *to, const void *, size_t);

#ifdef __cplusplus
}
#endif

#endif //__DSOTRE_WRAPPER_H__
