CR Search README.txt
=====================

 The idea behind this search module is a re-usable base for search functionality
 using Search API with Apache Solr as its back end.
 Results are returned via a Search API view.

 ** Rationale **

 Each campaign the content types listed by search have been re-implemented
 in order to take advantage of new theming practices.

 This module decouples the search feature from those content types, which can
 interact with search as outlined below.

 ** Modifications to the search feature **

 Additional indexes may be added using hook_default_search_api_index_alter().
 Additional views displays can be added using hook_default_views_alter().