#define GETTEXT_PACKAGE "pidgin-chatpop"

#define PURPLE_PLUGINS

#include "internal.h"

#include "account.h"
#include "blist.h"
#include "conversation.h"
#include "debug.h"
#include "signals.h"
#include "status.h"
#include "version.h"
#include "privacy.h"

#include "plugin.h"
#include "pluginpref.h"
#include "prefs.h"

#include "gtkconv.h"

#define PLUGIN_ID       "chatpop"
#define PLUGIN_NAME     N_("Chatpopper")
#define PLUGIN_SUMMARY  N_("Pop up closed buddy chat window on activity")
#define PLUGIN_DESC     N_("Causes chat windows for buddies to appear" \
                           " when activity appears in the chat")
#define PLUGIN_AUTHOR  "Paul Cowan <paul@custardsource.com>"
#define PLUGIN_VERSION "1.1"
#define PLUGIN_WEBSITE "https://developer.pidgin.im/ticket/5507"

static void
received_chat_msg_cb(PurpleAccount *acct, char *sender, char *buffer,
           PurpleConversation *chat, PurpleMessageFlags flags, void *data)
{
    pidgin_conv_attach_to_conversation(chat);
}


static gboolean
plugin_load(PurplePlugin *plugin) {

  void *convs_handle;
  convs_handle = purple_conversations_get_handle();


  purple_debug_info(PLUGIN_NAME, _("loaded.\n"));

  purple_signal_connect(convs_handle, "received-chat-msg",
      plugin, PURPLE_CALLBACK(received_chat_msg_cb), NULL);

  return TRUE;
}

static PurplePluginInfo info = {
  PURPLE_PLUGIN_MAGIC,
  PURPLE_MAJOR_VERSION,
  PURPLE_MINOR_VERSION,
  PURPLE_PLUGIN_STANDARD,   /**< type */
  NULL,                     /**< ui_requirement */
  0,                        /**< flags */
  NULL,                     /**< dependencies */
  PURPLE_PRIORITY_DEFAULT,  /**< priority */

  PLUGIN_ID,                /**< id */
  PLUGIN_NAME,              /**< name */
  PLUGIN_VERSION,           /**< version */
  PLUGIN_SUMMARY,           /**< summary */
  PLUGIN_DESC,              /**< description */
  PLUGIN_AUTHOR,            /**< author */
  PLUGIN_WEBSITE,           /**< homepage */

  plugin_load,              /**< load */
  NULL,                     /**< unload */
  NULL,                     /**< destroy */

  NULL,                     /**< ui_info */
  NULL,                     /**< extra_info */
  NULL,                     /**< prefs_info */
  NULL,                     /**< actions */

  /* padding */
  NULL,
  NULL,
  NULL,
  NULL
};


static void
init_plugin(PurplePlugin *plugin) {
}


PURPLE_INIT_PLUGIN(chatpop, init_plugin, info)
