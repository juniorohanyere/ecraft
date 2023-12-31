#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <espeak/speak_lib.h>

#include <ecraft.h>

/**
 * ec_tts - sets the tts flag to true
 *
 * Description: text to speech is disabled by default
 *
 * Return: return nothing
*/

void ec_tts(void)
{
	__ec->tts = EC_INIT;
}

/**
 * ec_ntts - sets the tts flag to false
 *
 * Description: default text to speech mode
 *
 * Return: return nothing
*/

void ec_ntts(void)
{
	__ec->tts = EC_NONE;
}

/**
 * __ec_tts - enables text to speech mode if tts flag is set to true
 *
 * @tts_msg: the text to convert to speech
 *
 * Description: tts flag (__ec->tts) is disabled by default
 *
 * Return: return nothing
*/

void __ec_tts(char *tts_msg)
{
	espeak_POSITION_TYPE pos_type = POS_CHARACTER;

	if (__ec->tts == EC_NONE)
		return;

	/* synthesize the speech */
	espeak_Synth(tts_msg, strlen(tts_msg) + 1, 0, pos_type, 0,
		espeakCHARS_AUTO, NULL, NULL);

	/* synchronize the speech */
	espeak_Synchronize();
}
