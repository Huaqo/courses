/*
 * Name: Joaquin Gottlebe
 * Matrikelnummer: 829101
 */

/**
 * The Taggable interface defines a generic type T
 * that allows objects to set and get a tag of type T.
 * 
 * @param <T> the type of the tag
 */
interface Taggable<T> {

	void setTag(T tag);

	T getTag();
}
