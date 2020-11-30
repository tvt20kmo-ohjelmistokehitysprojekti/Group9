<?php
defined('BASEPATH') OR exit('No direct script access allowed');

/*
| -------------------------------------------------------------------------
| URI ROUTING
| -------------------------------------------------------------------------
| This file lets you re-map URI requests to specific controller functions.
|
| Typically there is a one-to-one relationship between a URL string
| and its corresponding controller class/method. The segments in a
| URL normally follow this pattern:
|
| example.com/class/method/id/
|
| In some instances, however, you may want to remap this relationship
| so that a different class/function is called than the one
| corresponding to the URL.
|
| Please see the user guide for complete details:
|
| https://codeigniter.com/user_guide/general/routing.html
|
| -------------------------------------------------------------------------
| RESERVED ROUTES
| -------------------------------------------------------------------------
|
| There are three reserved routes:
|
| $route['default_controller'] = 'welcome';
|
| This route indicates which controller class should be loaded if the
| URI contains no data. In the above example, the "welcome" class
| would be loaded.
|
| $route['404_override'] = 'errors/page_missing';
|
| This route will tell the Router which controller/method to use if those
| provided in the URL cannot be matched to a valid route.
|
| $route['translate_uri_dashes'] = FALSE;
|
| This is not exactly a route, but allows you to automatically route
| controller and method names that contain dashes. '-' isn't a valid
| class or method name character, so it requires translation.
| When you set this option to TRUE, it will replace ALL dashes in the
| controller and method URI segments.
|
| Examples: my-controller/index -> my_controller/index
|   my-controller/my-method -> my_controller/my_method
*/
$route['default_controller'] = 'welcome';
$route['404_override'] = '';
$route['translate_uri_dashes'] = TRUE;

/*
| -------------------------------------------------------------------------
| Sample REST API Routes
| -------------------------------------------------------------------------
*/

$route['api/account/account/(:num)'] = '/api/account/account/id/$1';
$route['api/account/account/(:num)(\.)([a-zA-Z0-9_-]+)(.*)'] = '/api/account/account/id/$1/format/$3$4';

$route['api/client/client/(:num)'] = '/api/client/client/id/$1';
$route['api/client/client/(:num)(\.)([a-zA-Z0-9_-]+)(.*)'] = '/api/client/client/id/$1/format/$3$4';

$route['api/action/action/(:num)'] = '/api/action/action/id/$1';
$route['api/action/action/(:num)(\.)([a-zA-Z0-9_-]+)(.*)'] = '/api/action/action/id/$1/format/$3$4';

$route['api/deposit/deposit/(:num)'] = '/api/deposit/deposit/id/$1';
$route['api/deposit/deposit/(:num)(\.)([a-zA-Z0-9_-]+)(.*)'] = '/api/deposit/deposit/id/$1/format/$3$4';

$route['api/withdraw/withdraw/(:num)'] = '/api/withdraw/withdraw/id/$1';
$route['api/withdraw/withdraw/(:num)(\.)([a-zA-Z0-9_-]+)(.*)'] = '/api/withdraw/withdraw/id/$1/format/$3$4';

$route['api/transactions/transactions/(:num)'] = '/api/transactions/transactions/id/$1';
$route['api/transactions/transactions/(:num)(\.)([a-zA-Z0-9_-]+)(.*)'] = '/api/transactions/transactions/id/$1/format/$3$4';
