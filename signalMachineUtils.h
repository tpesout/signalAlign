#ifndef SIGNAL_H_
#define SIGNAL_H_

#include "pairwiseAlignment.h"

typedef struct _referenceSequence ReferenceSequence;
struct _referenceSequence {
    char *reference;
    char *reverseComplementOfReference;

    char *trimmedForwardSequence;
    char *trimmedBackwardSequence;

    struct PairwiseAlignment *A;  // pairwise alignment

    char *(*getTemplateTargetSequence)(ReferenceSequence *R);
    char *(*getComplementTargetSequence)(ReferenceSequence *R);

    bool initialized;
};

ReferenceSequence *signalUtils_ReferenceSequenceConstructFull(char *forwardReferencePath, char *backwardReferencePath,
                                                              struct PairwiseAlignment *pA);

ReferenceSequence *signalUtils_ReferenceSequenceConstructEmpty(struct PairwiseAlignment *pA);

void signalUtils_ReferenceSequenceSet(ReferenceSequence *self, char *forwardReferencePath, char *backwardReferencePath);

char *signalUtils_getSubSequence(char *seq, int64_t start, int64_t end, bool strand);

//void referenceSequence_loadReference(ReferenceSequence *R, char *forwardReferencePath, char *backwardReferencePath);

void signalUtils_ReferenceSequenceDestruct(ReferenceSequence *self);

void printFoo();

#endif