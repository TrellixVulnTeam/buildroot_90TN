#ifndef _ELM_INTERFACE_FILESELECTOR_EO_H_
#define _ELM_INTERFACE_FILESELECTOR_EO_H_

#ifndef _ELM_INTERFACE_FILESELECTOR_EO_CLASS_TYPE
#define _ELM_INTERFACE_FILESELECTOR_EO_CLASS_TYPE

typedef Eo Elm_Interface_Fileselector;

#endif

#ifndef _ELM_INTERFACE_FILESELECTOR_EO_TYPES
#define _ELM_INTERFACE_FILESELECTOR_EO_TYPES

/** Defines how a file selector widget is to layout its contents (file system
 * entries).
 *
 * @ingroup Elm_Fileselector
 */
typedef enum
{
  ELM_FILESELECTOR_LIST = 0, /**< Layout as a list. */
  ELM_FILESELECTOR_GRID, /**< Layout as a grid. */
  ELM_FILESELECTOR_LAST /**< Sentinel value to indicate last enum field during
                         * iteration */
} Elm_Fileselector_Mode;

/** Fileselector sorting modes
 *
 * @ingroup Elm_Fileselector
 */
typedef enum
{
  ELM_FILESELECTOR_SORT_BY_FILENAME_ASC = 0, /**< Alphabetical sort by ascending
                                              * filename, default */
  ELM_FILESELECTOR_SORT_BY_FILENAME_DESC, /**< Alphabetical sorting by
                                           * descending filename */
  ELM_FILESELECTOR_SORT_BY_TYPE_ASC, /**< Sort by file type */
  ELM_FILESELECTOR_SORT_BY_TYPE_DESC, /**< Sort by file type description */
  ELM_FILESELECTOR_SORT_BY_SIZE_ASC, /**< Sort by ascending file size */
  ELM_FILESELECTOR_SORT_BY_SIZE_DESC, /**< Sort by descending file size */
  ELM_FILESELECTOR_SORT_BY_MODIFIED_ASC, /**< Sort by ascending modified date */
  ELM_FILESELECTOR_SORT_BY_MODIFIED_DESC, /**< Sort by descending modified date
                                           */
  ELM_FILESELECTOR_SORT_LAST /**< Sentinel value to indicate last enum field
                              * during iteration */
} Elm_Fileselector_Sort;


#endif
/** Elementary fileselector interface
 *
 * @ingroup Elm_Interface_Fileselector
 */
#define ELM_INTERFACE_FILESELECTOR_INTERFACE elm_interface_fileselector_interface_get()

EWAPI const Efl_Class *elm_interface_fileselector_interface_get(void);

/**
 * @brief Enable/disable folder-only view for a given file selector widget
 *
 * @param[in] only @c true if folder view is set, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_folder_only_set(Eo *obj, Eina_Bool only);

/**
 * @brief Get whether folder-only view is set for a given file selector
 *
 * @return @c true if folder view is set, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool elm_interface_fileselector_folder_only_get(const Eo *obj);

/**
 * @brief Set the size for the thumbnail of the file selector widget's view.
 *
 * @param[in] w Width
 * @param[in] h Height
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_thumbnail_size_set(Eo *obj, int w, int h);

/**
 * @brief Get the size for the thumbnail of a given file selector widget
 *
 * @param[out] w Width
 * @param[out] h Height
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_thumbnail_size_get(const Eo *obj, int *w, int *h);

/**
 * @brief Enable or disable visibility of hidden files/directories in the file
 * selector widget.
 *
 * @param[in] hidden @c true if hidden files are visible, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_hidden_visible_set(Eo *obj, Eina_Bool hidden);

/**
 * @brief Get if hiden files/directories in the file selector are visible or
 * not.
 *
 * @return @c true if hidden files are visible, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool elm_interface_fileselector_hidden_visible_get(const Eo *obj);

/**
 * @brief Set the sort method of the file selector widget.
 *
 * @param[in] sort Sort method
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_sort_method_set(Eo *obj, Elm_Fileselector_Sort sort);

/**
 * @brief Get the sort method of the file selector widget.
 *
 * @return Sort method
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Elm_Fileselector_Sort elm_interface_fileselector_sort_method_get(const Eo *obj);

/**
 * @brief Enable or disable multi-selection in the fileselector
 *
 * @param[in] multi @c true if multiselection is enabled, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_multi_select_set(Eo *obj, Eina_Bool multi);

/**
 * @brief Gets if multi-selection in fileselector is enabled or disabled.
 *
 * @return @c true if multiselection is enabled, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool elm_interface_fileselector_multi_select_get(const Eo *obj);

/**
 * @brief Enable/disable a tree view in the given file selector widget, <b>if
 * it's in
 *
 * @param[in] expand @c true if tree view is expanded, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_expandable_set(Eo *obj, Eina_Bool expand);

/**
 * @brief Get whether tree view is enabled for the given file selector
 *
 * @return @c true if tree view is expanded, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool elm_interface_fileselector_expandable_get(const Eo *obj);

/**
 * @brief Set, programmatically, the directory that a given file selector
 * widget will display contents from
 *
 * @param[in] model Directory model
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_model_set(Eo *obj, Efl_Model *model);

/**
 * @brief Get the directory's model that a given file selector selector widget
 * display contents from
 *
 * @return Directory model
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Efl_Model *elm_interface_fileselector_model_get(const Eo *obj);

/**
 * @brief Set the mode in which a given file selector widget will display
 * (layout) file system entries in its view
 *
 * @param[in] mode Fileselector mode
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_mode_set(Eo *obj, Elm_Fileselector_Mode mode);

/**
 * @brief Get the mode in which a given file selector widget is displaying
 *
 * @return Fileselector mode
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Elm_Fileselector_Mode elm_interface_fileselector_mode_get(const Eo *obj);

/**
 * @brief Enable/disable the file name entry box where the user can type in a
 * name for a file, in a given file selector widget
 *
 * @param[in] is_save @c true if in saving mode, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_is_save_set(Eo *obj, Eina_Bool is_save);

/**
 * @brief Get whether the given file selector is in "saving dialog" mode
 *
 * @return @c true if in saving mode, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool elm_interface_fileselector_is_save_get(const Eo *obj);

/**
 * @brief Get a list of models selected in the fileselector.
 *
 * @return List of selected models
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI const Eina_List *elm_interface_fileselector_selected_models_get(const Eo *obj);

/**
 * @brief Current name property
 *
 * @param[in] name Name
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_current_name_set(Eo *obj, const char *name);

/**
 * @brief Current name property
 *
 * @return Name
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI const char *elm_interface_fileselector_current_name_get(const Eo *obj);

/**
 * @brief Set, programmatically, the currently selected file/directory in the
 * given file selector widget
 *
 * @param[in] model Model to be set
 *
 * @return Promise returning the recorded selected model or error
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Efl_Future *elm_interface_fileselector_selected_model_set(Eo *obj, Efl_Model *model);

/**
 * @brief Get the currently selected item's model, in the given file the given
 * file selector widget
 *
 * @return Selected model
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Efl_Model *elm_interface_fileselector_selected_model_get(Eo *obj);

/**
 * @brief Append custom filter into filter list
 *
 * @param[in] func Filter function
 * @param[in] data Data pointer
 * @param[in] filter_name Filter name
 *
 * @return @c true on success, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool elm_interface_fileselector_custom_filter_append(Eo *obj, Elm_Fileselector_Filter_Func func, void *data, const char *filter_name);

/** Clear all filters registered
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void elm_interface_fileselector_filters_clear(Eo *obj);

/**
 * @brief Append mime type based filter into filter list
 *
 * @param[in] mime_types Mime types
 * @param[in] filter_name Filter name
 *
 * @return @c true on success, @c false otherwise
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool elm_interface_fileselector_mime_types_filter_append(Eo *obj, const char *mime_types, const char *filter_name);

#endif
