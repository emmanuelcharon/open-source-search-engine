// Matt Wells, copyright Feb 2011

#ifndef _SYNONYMS_H_
#define _SYNONYMS_H_

#include "Xml.h"
#include "SafeBuf.h"
#include "StopWords.h"
#include "fctypes.h"

#define SOURCE_NONE       0
#define SOURCE_PRESET     1
#define SOURCE_WIKTIONARY 2
#define SOURCE_WIKTIONARY_EN 3
#define SOURCE_GENERATED  4
#define SOURCE_BIGRAM     5
#define SOURCE_TRIGRAM    6
#define SOURCE_NUMBER     7

// per word!
#define MAX_SYNS 64

#define TMPSYNBUFSIZE (MAX_SYNS*(8+8+8+1+4+4+4+4+4))

int64_t getSynBaseHash64 ( char *qstr , uint8_t langId ) ;

char *getSourceString ( char source );

class Synonyms {

 public:

	Synonyms();
	~Synonyms();

	void reset();

	long getSynonyms ( class Words *words , 
			   long wordNum , 
			   uint8_t langId ,
			   char *tmpBuf ,
			   long niceness ) ;

	
	bool addWithoutApostrophe ( long wordNum , class HashTableX *dt ) ;
	bool addAmpPhrase ( long wordNum , class HashTableX *dt ) ;
	bool addStripped ( char *w,long wlen, class HashTableX *dt ) ;

	long m_niceness;
	long m_version; // titlerec version

	//char    *m_langVec;
	char     m_docLangId;
	class Words *m_words;

	// temporarily store all synonyms here of the word for synonyms
	// like the accent-stripped version of the word. otherwise we
	// can just point to the wiktionary-buf.txt representation in memory.
	SafeBuf m_synWordBuf;

	// for each synonym of this word we fill out these:
	int64_t  *m_aids;
	int64_t  *m_wids0;
	int64_t  *m_wids1;
	char      **m_termPtrs;
	long       *m_termOffs;
	long       *m_termLens;
	long       *m_numAlnumWords;
	long       *m_numAlnumWordsInBase;
	char       *m_src;

	int64_t *m_aidsPtr;
	int64_t *m_wids0Ptr;
	int64_t *m_wids1Ptr;
	char     **m_termPtrsPtr;
	long      *m_termOffsPtr;
	long      *m_termLensPtr;
	long      *m_numAlnumWordsPtr;
	long      *m_numAlnumWordsInBasePtr;
	char      *m_srcPtr;

};

#endif
