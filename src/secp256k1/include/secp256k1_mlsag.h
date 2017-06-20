#ifndef _SECP256K1_MLSAG_
#define _SECP256K1_MLSAG_

#include "secp256k1.h"

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

int prepareLastRowMLSAG(size_t nOuts, size_t nBlinded, size_t nCols, size_t nRows,
    const uint8_t **pcm_in, const uint8_t **pcm_out, const uint8_t **blinds, 
    uint8_t *m, uint8_t *sk);

int getKeyImage(const secp256k1_context *ctx, const uint8_t *pk, const uint8_t *sk, uint8_t *ki);

int generateMLSAG(const secp256k1_context *ctx, const uint8_t *nonce,
    const uint8_t *preimage, size_t nCols, size_t nRows, size_t index,
    const uint8_t **sk, const uint8_t *pk, uint8_t *ki, uint8_t *pc, uint8_t *ps);

int verifyMLSAG(const secp256k1_context *ctx, const uint8_t *preimage,
    size_t nCols, size_t nRows,
    const uint8_t *pk, const uint8_t *ki, const uint8_t *pc, const uint8_t *ps);

#ifdef __cplusplus
}
#endif

#endif
