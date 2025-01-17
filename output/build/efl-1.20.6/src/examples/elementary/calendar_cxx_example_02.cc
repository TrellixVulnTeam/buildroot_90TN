#ifdef HAVE_CONFIG_H
#include "config.h"
#include "elementary_config.h"
#endif

#include <Efl.hh>
#include <Elementary.hh>

static char *
_format_month_year(struct tm *format_time)
{
   char buf[32];
   if (!strftime(buf, sizeof(buf), "%b %y", format_time)) return NULL;
   return strdup(buf);
}

EAPI_MAIN int
elm_main (int argc EINA_UNUSED, char **argv EINA_UNUSED)
{
   elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_HIDDEN);

   efl::ui::Win win;
   //win.title_set("Calendar Layout Formatting Example");
   win.autohide_set(true);

   ::elm::Calendar cal(win);
   //cal.size_hint_weight_set(EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   //win.resize_object_add(cal);

   cal.format_function_set(_format_month_year);
   // cal.weekdays_names_set(weekdays);

   cal.eo_cxx::efl::Gfx::size_set(125,134);  
   win.eo_cxx::efl::Gfx::size_set(125,134);
   cal.visible_set(true);
   win.visible_set(true);

   elm_run();
   return 0;
}
ELM_MAIN()
