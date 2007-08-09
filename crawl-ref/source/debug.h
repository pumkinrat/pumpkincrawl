/*
 *  File:       debug.h
 *  Summary:    Debug and wizard related functions.
 *  Written by: Linley Henzell and Jesse Jones
 *
 *  Modified for Crawl Reference by $Author$ on $Date$
 *
 *  Change History (most recent first):
 *
 *              <4>             5/30/99         JDJ             Added synch checks.
 *              <3>             5/06/99         JDJ             Added TRACE.
 *              <2>             -/--/--         JDJ             Added a bunch of debugging macros. Old code is now #if WIZARD.
 *              <1>             -/--/--         LRH             Created
 */
#ifndef DEBUG_H
#define DEBUG_H

// Synch with ANSI definitions.
#if DEBUG && defined(NDEBUG)
#error DEBUG and NDEBUG are out of sync!
#endif

#if !DEBUG && !defined(NDEBUG)
#error DEBUG and NDEBUG are out of sync!
#endif

// Synch with MSL definitions.
#if __MSL__ && DEBUG != defined(MSIPL_DEBUG_MODE)
#error DEBUG and MSIPL_DEBUG_MODE are out of sync!
#endif

// Synch with MSVC.
#if _MSC_VER >= 1100 && DEBUG != defined(_DEBUG)
#error DEBUG and _DEBUG are out of sync!
#endif


#ifndef _lint
#define COMPILE_CHECK(p)                        {struct _CC {char a[(p) ? 1 : -1];};} 0
#else
#define COMPILE_CHECK(p)
#endif

#if DEBUG

void AssertFailed(const char *expr, const char *file, int line);

#define ASSERT(p)       do {if (!(p)) AssertFailed(#p, __FILE__, __LINE__);} while (false)
#define VERIFY(p)       ASSERT(p)

void DEBUGSTR(const char *format,...);
void TRACE(const char *format,...);

#else

#define ASSERT(p)       ((void) 0)
#define VERIFY(p)       do {if (p) ;} while (false)

inline void __DUMMY_TRACE__(...)
{
}

#define DEBUGSTR                                                1 ? ((void) 0) : __DUMMY_TRACE__
#define TRACE                                                   1 ? ((void) 0) : __DUMMY_TRACE__

#endif


// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void cast_spec_spell(void);


// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void cast_spec_spell_name(void);


// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void create_spec_monster(void);


// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void create_spec_monster_name(int x = -1, int y = -1);


// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: ( this does not seem to be used at all ... {dlb} )
 * *********************************************************************** */
void create_spec_object(void);
void tweak_object(void);

// last updated 12say2001 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void debug_add_skills(void);
void debug_set_skills(void);
void debug_set_all_skills(void);

// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void debug_add_skills(void);

// last updated 17sep2001 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
bool debug_add_mutation(void);


// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: direct - food - items
 * *********************************************************************** */
void error_message_to_player(void);


// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void level_travel( int delta );
void wizard_interlevel_travel();

// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr - direct
 * *********************************************************************** */
void stethoscope(int mwh);

void debug_item_scan( void );
void debug_get_religion( void );
void debug_change_species( void );
void debug_fight_statistics( bool use_init_defaults, bool defence = false );
void debug_make_trap( void );
void debug_make_shop( void );
void debug_set_stats( void );
void debug_list_monsters();

void debug_card();
void debug_set_xl();
void debug_place_map();
void debug_test_explore();
void debug_dismiss_all_monsters();

#ifdef DEBUG_DIAGNOSTICS
void generate_map_stats();
class map_def;
void mapgen_report_map_try(const map_def &map);
void mapgen_report_map_use(const map_def &map);
void mapgen_report_error(const map_def &map, const std::string &err);
void mapgen_report_map_build_start();
void mapgen_report_map_veto();
#endif

#endif
